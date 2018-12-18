/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:34:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 11:59:28 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static t_metadata	*get_block(void *ptr)
{
	return ((t_metadata *)ptr - 1);
}

void		free(void *ptr)
{
	t_metadata	*block;

	ft_putendl(BLUE"in free"RESET);
	if (!ptr)
		return ;
	block = get_block(ptr);
	ft_putendl(BLUE"block->free"RESET);
	if (block->free)
		ft_putendl_fd("error malloc: double free", 2);
	block->free = 1;
	ft_putstr("block->size = ");
	ft_putnbr(block->size);
	ft_putchar('\n');
	ft_putendl(BLUE"out free"RESET);
}
