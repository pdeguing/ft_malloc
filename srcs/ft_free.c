/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:34:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 13:40:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static void	*get_block(void *ptr)
{
	return ((char *)ptr - META_SIZE);
}

void		free(void *ptr)
{
	t_metadata	*block;

//	ft_putendl(BLUE"in free"RESET);
	if (!ptr)
		return ;
	block = get_block(ptr);
//	ft_putendl(BLUE"block->free"RESET);
	block->free = 1;
//	ft_putstr("block->size = ");
//	ft_putnbr(block->size);
//	ft_putchar('\n');
//	ft_putendl(BLUE"out free"RESET);
}
