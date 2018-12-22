/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:29:51 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 16:03:15 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*calloc(size_t count, size_t size)
{
	size_t	alloc_size;
	void	*ptr;

	if (!count || !size)
		return (NULL);
	alloc_size = count * size;
	ptr = malloc(alloc_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, alloc_size);
	return (ptr);
}
