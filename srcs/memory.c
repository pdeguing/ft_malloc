/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:25:20 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 08:35:47 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void	*request_memory(size_t size)
{
	void	*ptr;
	t_metadata	*new;

	ptr = mmap(0, size + sizeof(t_metadata),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED || !ptr)
		return (NULL);
	new = (t_metadata *)ptr;
	new->size = size;
	new->next = NULL;
	return (new + 1);
}
