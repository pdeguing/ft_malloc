/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 08:52:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*malloc(size_t size)
{
	void			*ptr;
	struct rlimit	rlp;

	getrlimit(RLIMIT_DATA, &rlp);
	if (!size || size > rlp.rlim_cur)
		return (NULL);
	ft_putendl(RED"malloc"RESET);
	ptr = free_list_pop(&g_free_list, size);
	if (!ptr)
	{
		ft_putendl(RED"mmap"RESET);
		ptr = request_memory(size);
	}
	return (ptr);
}
