/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 17:09:25 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

/*
** We call malloc_zone_free_list_retrieve() to update the free list with
** the spare block, but we don't actually need the pointer it returns because
** it is continuous with our block and is now part of it.
*/

static void	*realloc_block_enlarge(t_zone *zone, t_free *block, size_t request_size)
{
	t_free	*free_block;
	t_free	*prev_block;
	size_t	spare_size;

	if (!zone->list)
		return (NULL);
	free_block = zone->list;
	prev_block = NULL;
	while (free_block)
	{
		if (free_block == (t_free *)((char *)block + (block->size & BIT_FREE) + 32))
		{
			spare_size = free_block->size - request_size - (block->size & BIT_FREE);
			if (spare_size == 0)
			{
				zone->free_size -= free_block->size;
				if (prev_block)
					prev_block->next = free_block->next;
				else
					zone->list = free_block->next;
				block->size = request_size | BIT_ALLOC;
				return ((char *)block + SIZE_T_SIZE);
			}
			else if (spare_size > 0)
			{
				zone->free_size -= (free_block->size - spare_size);
				block->next = free_block->next;
				free_block = (t_free *)((char *)free_block + request_size - (block->size & BIT_FREE));
				free_block->size = spare_size;
				free_block->next = block->next;
				if (prev_block)
					prev_block->next = free_block;
				else
					zone->list = free_block;
				block->size = request_size | BIT_ALLOC;
				return ((char *)block + SIZE_T_SIZE);
			}
			return (NULL);
		}
		prev_block = free_block;
		free_block = free_block->next;
	}
	return (NULL);
}

static void	*realloc_block_update(t_zone *zone, t_free *block, size_t request_size)
{
	t_free	*spare_block;

	if (block->size == request_size)
		return ((char *)block + SIZE_T_SIZE);
	if (block->size > request_size)
	{
		spare_block = (t_free *)((char *)block + block->size - request_size);
		spare_block->size = block->size - request_size;
		block->size = request_size;
		free((char *)spare_block + SIZE_T_SIZE);
		return ((char *)block + SIZE_T_SIZE);
	}
	return (realloc_block_enlarge(zone, block, request_size));
}

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_free	*ptr_block;
	void	*new_ptr;
	size_t	request_size;

	if (!ptr)
	{
		return (malloc(size));
	}
	zone = get_zone(ptr);
	if (!zone)
	{
		return (NULL);
	}
	ptr_block = (t_free *)((char *)ptr - SIZE_T_SIZE);
	request_size = align_request_size(size);
	new_ptr = NULL;
	if (get_zone_list_index(ptr_block->size & BIT_FREE) == get_zone_list_index(request_size)
			&& (zone->free_size >= request_size || ptr_block->size >= request_size))
		new_ptr = realloc_block_update(zone, ptr_block, request_size);
	if (!new_ptr)
	{
		new_ptr = malloc(size);
		if (!new_ptr)
		{
			return (NULL);
		}
		ft_memcpy(new_ptr, ptr, MIN((ptr_block->size & BIT_FREE) - T_FREE_SIZE, size));
		free(ptr);
	}
	return (new_ptr);
}
