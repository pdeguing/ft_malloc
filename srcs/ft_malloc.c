/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/20 18:30:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static size_t	align_request_size(size_t size)
{
	if (IS_TINY(size))
		return (ALIGN(ALIGN_TINY, size));
	if (IS_SMALL(size))
		return (ALIGN(ALIGN_SMALL, size));
	return (ALIGN(ALIGN_PAGE, size + T_ZONE_SIZE));
}

void	*malloc(size_t size)
{
	struct rlimit	rlp;
	size_t			request_size;
	void			*ptr;

	//_PUTSTR_(RED"malloc: in"RESET);
	//_PUTNBR_("size", size);
	getrlimit(RLIMIT_DATA, &rlp);
	request_size = align_request_size(size + SIZE_T_SIZE);
	if (request_size > rlp.rlim_cur)
		return (NULL);
	ptr = malloc_zone_request_block(request_size);
	//_PUTSTR_(RED"malloc: out"RESET);
	return (ptr);
}
