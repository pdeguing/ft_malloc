/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:14 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 17:01:00 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static void	*create_list(t_obj *ptr, size_t object_count)
{
	t_obj	*head;
	size_t	i;

	head = ptr;
	i = 0;
	while (i < object_count)
	{
		head->next = ptr + i;
		head = head->next;
		i++;
	}
	head->next = NULL;
	return (ptr);
}

static size_t	get_object_count(size_t size)
{
	size_t		n;
	size_t		page_size;

	page_size = getpagesize();
	n = page_size / size;
	if (n < 100)
		n = 100;
	return (n);
}

t_span		*span_create(size_t size)
{
	t_span	*new;
	size_t	total_size;
	size_t	object_size;
	size_t	object_count;
	size_t	offset;

	ft_putendl("-> span_create():"); ////////////////
	if (size <= TINY)
		object_size = TINY;
	else
		object_size = SMALL;
	object_count = get_object_count(size);
	total_size = object_size * object_count;
	new = (t_span *)mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (new == MAP_FAILED || !new)
		return (NULL);
	offset = 1;
	if (size <= TINY && TINY < 16)
		offset = 2;
	new->data = create_list((t_obj *)new + offset, object_count - offset);
	new->next = NULL;
	return (new);
}
