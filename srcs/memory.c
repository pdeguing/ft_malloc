/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:25:20 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 13:19:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

static size_t	request_large_size(size_t size)
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

static size_t	request_size_get(size_t size)
{
	size_t	request_size;

	request_size = size + sizeof(t_metadata);
	if (request_size <= TINY)
		request_size = TINY;
	else if (request_size <= SMALL)
		request_size = SMALL;
	else
		request_size = request_large_size(request_size);
	return (request_size);
}

void	*request_memory(size_t size)
{
	void	*ptr;
	t_metadata	*new;
	size_t	request_size;

	request_size = request_size_get(size);
//	ft_putstr("request_size = ");
//	ft_putnbr(request_size);
//	ft_putchar('\n');
	ptr = mmap(0, request_size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED || !ptr)
		return (NULL);
	new = (t_metadata *)ptr;
	new->size = size;
	new->next = NULL;
	new->free = 0;
	return (new + 1);
}
