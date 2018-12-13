/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/13 14:08:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

/*
void	*realloc(void *ptr, size_t size)
{
	void	*new;

	new = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (new == MAP_FAILED)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
*/
