/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 14:47:29 by pdeguing         ###   ########.fr       */
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
	ptr = free_list_pop(&g_free_list, size);
	if (!ptr)
	{
		ptr = request_memory(size);
		free_list_push(&g_free_list, (t_metadata *)ptr - 1);
	}
	return (ptr);
}
