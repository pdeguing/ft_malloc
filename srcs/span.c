/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:50:14 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 12:37:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static void	*create_list(t_obj *ptr, size_t total_size, size_t object_size)
{
	t_obj	*head;
	size_t	i;

	(void)object_size;
	ft_putendl("1");
	ft_putnbr(sizeof(t_obj));
	ft_putchar(' ');
	head = ptr;
	i = 0;
	ft_putendl("2");
	ft_putnbr(total_size);
	ft_putchar('\n');
	while (i < total_size)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		head->next = ptr + i;
		head = head->next;
		i++;
	}
	ft_putendl("3");
	head->next = NULL;
	return (ptr);
}

t_span		*span_create(size_t size)
{
	t_span	*new;
	size_t	total_size;
	size_t	object_size;

	if (size <= TINY)
		object_size = TINY;
	else if (size <= SMALL)
		object_size = SMALL;
	else
		object_size = 0;
	total_size = object_size * 512; // need to compute the number of objects
	new = (t_span *)mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (new == MAP_FAILED || !new)
		return (NULL);
	new->list = create_list((t_obj *)new + 2, 510, object_size);
	new->next = NULL;
	return (new);
}
