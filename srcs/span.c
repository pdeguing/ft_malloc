/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:14 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/14 12:40:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static void	*span_list_create(size_t size)
{
	void	*ptr;
	size_t	span_size;
	size_t	object_size;
	size_t	i;

	if (size <= TINY)
		object_size = TINY;
	else if (size <= SMALL)
		object_size = SMALL;
	else
		object_size = 0;
	span_size = object_size * 512; // need to compute the number of objects
	ptr = mmap(0, span_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	/* emulate linked list by storing address of next block inside each block */
	i = 0;
	while (i < span_size - object_size)
	{
		ptr + i = ptr + i + object_size;
		i += object_size;
	}
	ptr + i = NULL;
	return (ptr);
}

t_span		span_create(size_t size)
{
	t_span	new;
	void	*ptr;

	ptr = span_list_create(size);
	new.list = (t_obj *)ptr;
	new.next = NULL;
	return (new);
}
