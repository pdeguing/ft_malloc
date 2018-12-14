/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:10:42 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/14 12:33:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

int			cache_check_availability(size_t size)
{
	(void)size;
	return (0);
}

void		*cache_pull(size_t size)
{
	(void)size;
	return (NULL);
}

void		cache_push_object(void *ptr, t_span span)
{
	t_obj	*head;

	head = span.list;
	while (head->next)
	{
		head = head->next;
	}
	head->next = ptr;
}

void		cache_push_span(t_span span, size_t size)
{
	t_span	*head;
	int		i;

	if (size <= TINY)
		i = 0;
	else if (size <= SMALL)
		i = 1;
	else
		i = 2;
	head = g_cache[i];
	if (!head)
	{
		g_cache[i] = &span;
		return ;
	}
	while (head->next)
	{
		head = head->next;
	}
	head->next = &span;
}
