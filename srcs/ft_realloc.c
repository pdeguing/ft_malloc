/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/22 15:22:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

/*
** We call malloc_zone_free_list_retrieve() to update the free list with
** the spare block, but we don't actually need the pointer it returns because
** it is continuous with our block and is now part of it.
*/

static void	*full_block(t_zone *zone, t_free *free,
		t_free *prev_block, size_t request)
{
	t_free	*block;

	block = prev_block->next;
	zone->free_size -= free->size;
	if (prev_block)
		prev_block->next = free->next;
	else
		zone->list = free->next;
	block->size = request | BIT_ALLOC;
	return ((char *)block + SIZE_T_SIZE);
}

static void	*part_block(t_zone *zone, t_free *free,
		t_free *prev_block, size_t request)
{
	size_t	spare;
	t_free	*block;

	block = prev_block->next;
	spare = free->size - request - (block->size & BIT_FREE);
	zone->free_size -= (free->size - spare);
	block->next = free->next;
	free = (t_free *)((char *)free + request
			- (block->size & BIT_FREE));
	free->size = spare;
	free->next = block->next;
	if (prev_block)
		prev_block->next = free;
	else
		zone->list = free;
	block->size = request | BIT_ALLOC;
	return ((char *)block + SIZE_T_SIZE);
}

static void	*block_enlarge(t_zone *zone, t_free *block,
		size_t request)
{
	t_free	*free;
	t_free	*prev_block;
	size_t	spare;

	if (!zone->list)
		return (NULL);
	free = zone->list;
	prev_block = NULL;
	while (free)
	{
		if (free == (t_free *)((char *)block +
					(block->size & BIT_FREE) + 32))
		{
			spare = free->size - request - (block->size & BIT_FREE);
			if (spare == 0)
				return (full_block(zone, free, prev_block, request));
			else if (spare > 0)
				return (part_block(zone, free, prev_block, request));
			return (NULL);
		}
		prev_block = free;
		free = free->next;
	}
	return (NULL);
}

static void	*block_update(t_zone *zone, t_free *block,
		size_t request)
{
	t_free	*spare_block;

	if (block->size == request)
		return ((char *)block + SIZE_T_SIZE);
	if (block->size > request)
	{
		spare_block = (t_free *)((char *)block + block->size - request);
		spare_block->size = block->size - request;
		block->size = request;
		free((char *)spare_block + SIZE_T_SIZE);
		return ((char *)block + SIZE_T_SIZE);
	}
	return (block_enlarge(zone, block, request));
}

void		*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_free	*block;
	void	*new_ptr;
	size_t	request;

	if (!ptr)
		return (malloc(size));
	if (!(zone = get_zone(ptr)))
		return (NULL);
	block = (t_free *)((char *)ptr - SIZE_T_SIZE);
	request = align_request_size(size);
	new_ptr = NULL;
	if (INDEX_CMP(block->size, request) &&
			(zone->free_size >= request || block->size >= request))
		new_ptr = block_update(zone, block, request);
	if (!new_ptr)
	{
		new_ptr = malloc(size);
		if (!new_ptr)
			return (NULL);
		ft_memcpy(new_ptr, ptr,
				MIN((block->size & BIT_FREE) - T_FREE_SIZE, size));
		free(ptr);
	}
	return (new_ptr);
}
