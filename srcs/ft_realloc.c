/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/19 12:50:21 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*realloc(void *ptr, size_t size)
{
	void	*new;
	size_t	*header;
	size_t	ptr_size;

	ft_putendl(PINK"in realloc"RESET);
	ft_putnbr(size);
	ft_putchar('\n');
	new = malloc(size);
	if (!new)
		return (NULL);
	if (ptr)
	{
		header = (size_t *)((char *)ptr - HEADER_SIZE);
		ptr_size = *header;
		ft_memcpy(new, ptr, ptr_size);
		free(ptr);
	}
	return (new);
}
