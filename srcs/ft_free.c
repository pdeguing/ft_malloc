/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:34:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/19 12:50:21 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		free(void *ptr)
{
	size_t		*header;

	ft_putendl(BLUE"in free"RESET);
	if (ptr)
	{
		header = (size_t *)((char *)ptr - HEADER_SIZE);
		*header = *header & FREE;
		ft_putnbr(*header);
		ft_putchar('\n');
	}
}
