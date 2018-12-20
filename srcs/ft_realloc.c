/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:35:03 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/20 13:34:13 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*realloc(void *ptr, size_t size)
{
	_PUTSTR_(PINK"realloc: in"RESET);
	(void)ptr;
	(void)size;
	_PUTSTR_(PINK"realloc: out"RESET);
	return (NULL);
}
