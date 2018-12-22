/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:17:19 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/22 15:25:49 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		print_free_list(t_free *block)
{
	if (!block)
		_PUTSTR_("free_list is empty");
	while (block)
	{
		ft_printf("%p - %p : %d bytes\n", block,
				block + block->size, block->size);
		block = block->next;
	}
}

void		print_zone(t_zone *zone)
{
	t_free	*block;
	size_t	read_size;

	read_size = T_ZONE_SIZE;
	block = (t_free *)((char *)zone + T_ZONE_SIZE);
	while (read_size < zone->size)
	{
		if (block->size & 1)
			ft_putstr(RED);
		else
			ft_putstr(GREEN);
		ft_printf("%p - %p : %d bytes\n", block,
				(char *)block + (block->size & BIT_FREE), block->size);
		ft_putstr(RESET);
		read_size += (block->size & BIT_FREE);
		block = (t_free *)((char *)block + (block->size & BIT_FREE));
	}
}

void		print_list(t_zone *zone)
{
	while (zone)
	{
		if (zone->size == ZONE_TINY)
			ft_printf("TINY  : ");
		else if (zone->size == ZONE_SMALL)
			ft_printf("SMALL : ");
		else
			ft_printf("LARGE : ");
		ft_printf(" %p\n", zone);
		print_zone(zone);
		zone = zone->next;
	}
}

void		show_alloc_mem(void)
{
	print_list(g_zone_list[INDEX_TINY]);
	print_list(g_zone_list[INDEX_SMALL]);
	print_list(g_zone_list[INDEX_LARGE]);
}
