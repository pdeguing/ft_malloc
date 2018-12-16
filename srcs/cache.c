/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:10:42 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 17:15:31 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

int			cache_check_availability(size_t size)
{
	(void)size;
	return (0);
}

void		*cache_pull_large(size_t size)
{
	void	*ptr;
	t_span	*span;
	t_large	*object;

	ft_putendl("--> cache_pull_large()"); /////////////////
	span = g_cache[INDEX_LARGE];
	object = NULL;
	while (span)
	{
		object = (t_large *)span->data;
		if (object && size <= object->size)
		{
			ptr = object->ptr;
			span->data = NULL;
			return (ptr);
		}
		span = span->next;
	}
	return (NULL);
}

void		*cache_pull(int i)
{
	void	*ptr;
	t_span	*span;
	t_obj	*list;

	ft_putendl("--> cache_pull()"); //////////////////
	span = g_cache[i];
	if (!span)
		ft_putendl("---> !span");
	while (span)
	{
		if (!span)
			ft_putendl("---> !span");
		if (span->data)
		{
			ft_putendl("---> span->data");
			list = (t_obj *)span->data;
			ptr = (void *)list;
			list = list->next;
			span->data = (void *)list;
			return (ptr);
		}
		ft_putendl("---> span = span->next");
		span = span->next;
	}
	ft_putendl("---> return (NULL)");
	return (NULL);
}

void		cache_push_object(void *ptr, t_span *span)
{
	t_obj	*head;

	head = span->data;
	while (head->next)
	{
		head = head->next;
	}
	head->next = ptr;
}

void		cache_push_span(t_span *span, int i)
{
	t_span	*head;

	ft_putendl("--> cache_push_span()"); //////////////////////
	head = g_cache[i];
	if (!head)
	{
		ft_putendl("---> !head");
		g_cache[i] = span;
		return ;
	}
	while (head->next)
	{
		head = head->next;
	}
	head->next = span;
}
