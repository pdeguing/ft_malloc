/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/13 09:53:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

int		cache_available(size_t size)
{
	(void)size;
	return (0);
}

void	*cache_retrieve(size_t size)
{
	(void)size;
	return (NULL);
}

void	*allocate_mem(size_t size)
{
	void	*ptr;

	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}

void	*malloc(size_t size)
{
	void	*ptr;

	if (!size || size > getrlimit())
		return (NULL);
	if (cache_available(size))
		return (cache_retrieve(size));
	return (allocate_mem(size));
}
