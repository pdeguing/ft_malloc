/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:17:19 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/20 12:44:24 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		print_free_list(t_free *block)
{
	_PUTSTR_(PINK);
	if (!block)
		_PUTSTR_("		free_list is empty");
	while (block)
	{
		_PUTNBR_("		block_address", (int)block);
		_PUTNBR_("		block->size", block->size);
		block = block->next;
	}
	_PUTSTR_(RESET);
}

void		print_zone(t_zone *zone)
{
	_PUTSTR_(BLUE);
	_PUTNBR_("	zone_address", (int)zone);
	_PUTNBR_("	zone_size", zone->size);
	_PUTNBR_("	free_size", zone->free_size);
	_PUTFREE_(zone->list);
	_PUTSTR_(RESET);
}

void		show_alloc_mem(void)
{
	size_t	*header;

	header = NULL;
	if (!header)
		return ;
}
