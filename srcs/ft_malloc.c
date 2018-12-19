/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 16:18:14 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*malloc(size_t size)
{
//	struct rlimit	rlp;
	size_t			block_size;
	size_t			*header;
//	static int		init;

//	getrlimit(RLIMIT_DATA, &rlp);
//	if (!size || size > rlp.rlim_cur)
//		return (NULL);
//	if (!init)
//	{
//		header = mmap(0, HEADER_SIZE,
//				PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//		init = 1;
//		*header = 0;
//		g_heap = header;
//	}
	block_size = ALIGN(size + HEADER_SIZE);
	header = mmap(0, block_size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	*header = block_size | ALLOCATED;
	return ((char *)header + HEADER_SIZE);
}
