/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_zone_defrag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:02:34 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 14:22:25 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		malloc_zone_defrag(t_free *block)
{
	if (!block)
		return ;
	while (block && block->next)
	{
		if (block + block->size == block->next)
		{
			block->size += block->next->size;
			block->next = block->next->next;
		}
		block = block->next;
	}
}
