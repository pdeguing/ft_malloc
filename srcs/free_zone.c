/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:58:29 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 16:05:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static void		free_zone_free_list_insert(t_zone *zone, t_free *new_block)
{
	t_free	*free_block;
	t_free	*prev_block;

	free_block = zone->list;
	prev_block = NULL;
	while (free_block)
	{
		if (!free_block->next)
		{
			free_block->next = new_block;
			return ;
		}
		if (new_block < free_block)
		{
			if (prev_block)
				prev_block->next = new_block;
			else
				zone->list = new_block;
			new_block->next = free_block;
			return ;
		}
		prev_block = free_block;
		free_block = free_block->next;
	}
}

void	free_zone_free_list_add(t_zone *zone, void *ptr)
{
	t_free	*new_block;

	new_block = (t_free *)((char *)ptr - SIZE_T_SIZE);
	zone->free_size += new_block->size;
	new_block->size &= BIT_FREE;
	new_block->next = NULL;
	if (!zone->list)
	{
		zone->list = new_block;
		return ;
	}
	free_zone_free_list_insert(zone, new_block);
}
