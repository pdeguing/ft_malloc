/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/20 18:03:24 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	t_free	*ptr_block;
	void	*new_ptr;

	//_PUTSTR_(BLUE"realloc: in"RESET);
	//_PUTNBR_(BLUE"size"RESET, size);
	if (!ptr)
	{
		//_PUTSTR_(BLUE"realloc: return (malloc)"RESET);
		return (malloc(size));
	}
	zone = get_zone(ptr);
	//_PUTSTR_(BLUE"realloc: get_zone"RESET);
	if (!zone)
	{
		//_PUTSTR_(BLUE"realloc: !zone"RESET);
		return (NULL);
	}
	new_ptr = malloc(size);
	//_PUTSTR_(BLUE"realloc: malloc"RESET);
	if (!new_ptr)
	{
		//_PUTSTR_(BLUE"realloc: !new_ptr"RESET);
		return (NULL);
	}
	ptr_block = (t_free *)((char *)ptr - SIZE_T_SIZE);
	//_PUTNBR_(BLUE"ptr_size"RESET, ptr_block->size);
	//_PUTNBR_(BLUE"MIN"RESET, MIN(ptr_block->size - T_FREE_SIZE, size));
	ft_memcpy(new_ptr, ptr, MIN(ptr_block->size - T_FREE_SIZE, size));
	//_PUTSTR_(BLUE"realloc: ft_memcpy"RESET);
	free(ptr);
	//_PUTSTR_(BLUE"realloc: out"RESET);
	return (new_ptr);
}
