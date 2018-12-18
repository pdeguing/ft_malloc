/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:14:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 08:52:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

int			free_list_is_empty(t_metadata **free_list)
{
	if (!free_list || !*free_list)
		return (1);
	return (0);
}

void		*free_list_pop(t_metadata **free_list, size_t size)
{
	t_metadata	*ret;
	t_metadata	*head;
	t_metadata	*prev;

	if (free_list_is_empty(free_list))
		return (NULL);
	head = *free_list;
	prev = NULL;
	while (head)
	{
		if (head->size >= size)
		{
			if (prev)
				prev->next = head->next;
			else
				*free_list = head->next;
			ret = head + 1;
			return (ret);
		}
		prev = head;
		head = head->next;
	}
	return (NULL);
}

void		free_list_push(t_metadata **free_list, t_metadata *block)
{
	if (free_list_is_empty(free_list))
	{
		*free_list = block;
		return ;
	}
	block->next = *free_list;
	*free_list = block;
}
