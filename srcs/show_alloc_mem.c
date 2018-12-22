/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:17:19 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 20:33:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		print_free_list(t_free *block)
{
	_PUTSTR_(PINK);
	if (!block)
		_PUTSTR_("free_list is empty");
	while (block)
	{
		_PUTNBR_("block_address", (int)block);
		_PUTNBR_("block->size", block->size);
		block = block->next;
	}
	_PUTSTR_(RESET);
}

void		print_zone(t_zone *zone)
{
	if (!zone)
	{
		_PUTSTR_("		zone is NULL");
		return ;
	}
	_PUTFREE_(zone->list);
}

void		print_list(t_zone *zone)
{
	while (zone)
	{
		print_zone(zone);
		zone = zone->next;
	}
}

void		show_alloc_mem(void)
{
	_PUTSTR_("TINY:");
	print_list(g_zone_list[INDEX_TINY]);
	_PUTSTR_("SMALL:");
	print_list(g_zone_list[INDEX_SMALL]);
	_PUTSTR_("LARGE:");
	print_list(g_zone_list[INDEX_LARGE]);
}
