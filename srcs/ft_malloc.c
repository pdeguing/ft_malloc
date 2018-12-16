/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 17:15:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static int	get_cache_index(size_t size)
{
	if (size <= TINY)
		return (0);
	return (1);
}

void	*malloc(size_t size)
{
	int				cache_index;
	void			*ptr;
	struct rlimit	rlp;

	ft_putendl("-> malloc()"); //////////////
	ft_putstr("-> size = ");
	ft_putnbr(size);
	ft_putchar('\n');
	getrlimit(RLIMIT_DATA, &rlp);
	if (!size || size > rlp.rlim_cur)
		return (NULL);
	if (size > SMALL)
		return (large_object(size));
	cache_index = get_cache_index(size);
	ptr = cache_pull(cache_index);
	if (!ptr)
	{
		cache_push_span(span_create(size), cache_index);
		ft_putstr("-> ");
		ft_putnbr(cache_index);
		ft_putchar('\n');
		return (cache_pull(cache_index));
	}
	return (ptr);
}
