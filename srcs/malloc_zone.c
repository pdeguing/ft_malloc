/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:42:34 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 16:06:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static t_zone	*malloc_zone_create(size_t zone_size)
{
	t_zone	*zone;

	zone = (t_zone *)mmap(0, zone_size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (zone == MAP_FAILED || !zone)
		return (NULL);
	zone->size = zone_size;
	zone->free_size = zone_size - T_ZONE_SIZE;
	zone->list = (t_free *)(zone + 1);
	zone->list->size = zone->free_size;
	zone->list->next = NULL;
	zone->next = NULL;
	return (zone);
}

void	*malloc_zone_free_list_retrieve(t_zone *zone, t_free *free_block, t_free *prev_block, size_t request_size)
{
	t_free	*new_block;
	void	*ptr;

	new_block = free_block;
	if (free_block->size > request_size)
	{
		free_block = (t_free *)((char *)free_block + request_size);
		free_block->size = new_block->size - request_size;
		free_block->next = new_block->next;
		new_block->size = request_size | BIT_ALLOC;
		new_block->next = free_block;
	}
	if (prev_block)
		prev_block->next = new_block->next;
	else
		zone->list = new_block->next;
	ptr = (void *)((char *)new_block + SIZE_T_SIZE);
	return (ptr);
}

static void	*malloc_zone_retrieve_block(t_zone *zone, size_t request_size)
{
	void	*ptr;
	t_free	*free_block;
	t_free	*prev_block;

	if (!zone->list || zone->free_size < request_size)
		return (NULL);
	ptr = NULL;
	free_block = zone->list;
	prev_block = NULL;
	while (free_block && !ptr)
	{
		if (free_block->size >= request_size)
			ptr = malloc_zone_free_list_retrieve(zone, free_block, prev_block, request_size);
		prev_block = free_block;
		free_block = free_block->next;
	}
	if (!ptr)
	{
		malloc_zone_defrag(zone->list);
		ptr = malloc_zone_retrieve_block(zone, request_size);
	}
	zone->free_size -= request_size;
	return (ptr);
}

static void	malloc_zone_list_add(int index, t_zone *new_zone)
{
	t_zone	*head;

	head = g_zone_list[index];
	if (!head)
	{
		g_zone_list[index] = new_zone;
		return ;
	}
	while (head)
	{
		if (!head->next)
		{
			head->next = new_zone;
			return ;
		}
		head = head->next;
	}
}

void	*malloc_zone_request_block(size_t request_size)
{
	void	*ptr;
	t_zone	*zone;
	size_t	zone_size;
	int		zone_list_index;

	ptr = NULL;
	zone_list_index = get_zone_list_index(request_size);
	zone = g_zone_list[zone_list_index];
	while (zone && !ptr)
	{
		ptr = malloc_zone_retrieve_block(zone, request_size);
		zone = zone->next;
	}
	if (!ptr)
	{
		zone_size = get_zone_size(request_size);
		if (IS_LARGE(request_size))
			request_size -= T_ZONE_SIZE;
		zone = malloc_zone_create(zone_size);
		ptr = malloc_zone_retrieve_block(zone, request_size);
		malloc_zone_list_add(zone_list_index, zone);
	}
	return (ptr);
}
