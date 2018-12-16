/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:07:59 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 16:30:39 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static size_t	get_map_size(size_t size)
{
	size_t		page_size;
	size_t		page_count;

	page_size = getpagesize();
	if (size < page_size - 4)
		return (page_size);
	page_count = size / page_size;
	if (size % page_size)
		page_count++;
	return (page_count * page_size);
}

/*
void	large_push(t_span *new, size_t size)
{
	t_span	*head;
	t_span	*prev;

	head = g_cache[INDEX_LARGE];
	if (!head)
	{
		g_cache[INDEX_LARGE] = new;
		return ;
	}
	prev = NULL;
	while (head)
	{
		if (!head->next)
		{
			head->next = new;
			return ;
		}
		if (head->size > size)
		{
			new->next = head;
			if (prev)
				prev->next = new;
			else
				g_cache[INDEX_LARGE] = new;
			return ;
		}
		prev = head;
		head = head->next;
	}
}
*/

t_span	*large_create(size_t size)
{
	size_t		map_size;
	t_span		*span;
	t_large		*new;

	map_size = get_map_size(size + LARGE_META);
	span = (t_span *)mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new = (t_large *)((t_span *)span + 1);
	new->size = size;
	new->ptr = new + 1; 
	span->data = new;
	span->next = NULL;
	return (span);
}

void	*large_object(size_t size)
{
	void	*ptr;

	ft_putendl("-> large_object():"); ////////////////////
	ptr = cache_pull_large(size);
	if (!ptr)
	{
		cache_push_span(large_create(size), INDEX_LARGE);
		ptr = cache_pull_large(size);
	}
	return (ptr);
}
