/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 11:41:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*realloc(void *ptr, size_t size)
{
	void	*new;

	ft_putendl(PINK"in realloc"RESET);
	new = malloc(size);
	if (new)
		ft_memcpy(new, ptr, size);
	free(ptr);
	ft_putendl(PINK"out realloc"RESET);
	return (new);
}
