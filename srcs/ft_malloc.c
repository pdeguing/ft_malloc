/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 20:33:55 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

size_t	align_request_size(size_t size)
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

	getrlimit(RLIMIT_DATA, &rlp);
	request_size = align_request_size(size + SIZE_T_SIZE);
	if (request_size > rlp.rlim_cur)
		return (NULL);
	ptr = malloc_zone_request_block(request_size);
	return (ptr);
}
