/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/13 11:28:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static int		cache_available(size_t size)
{
	(void)size;
	return (0);
}

static void		*cache_retrieve(size_t size)
{
	(void)size;
	return (NULL);
}

static void		*allocate_mem(size_t size)
{
	void	*ptr;

	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}

void	*malloc(size_t size)
{
	struct rlimit	rlp;

	getrlimit(RLIMIT_DATA, &rlp);
	if (!size || size > rlp.rlim_cur)
		return (NULL);
	if (cache_available(size))
		return (cache_retrieve(size));
	return (allocate_mem(size));
}
