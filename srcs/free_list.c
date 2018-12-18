/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:14:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 14:43:15 by pdeguing         ###   ########.fr       */
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
	t_metadata	*head;

	if (free_list_is_empty(free_list))
		return (NULL);
	head = *free_list;
	while (head)
	{
		if (head->free && head->size >= size)
		{
			head->free = 0;
			return ((void *)head + 1);
		}
		head = head->next;
	}
	return (NULL);
}

void		free_list_push(t_metadata **free_list, t_metadata *block)
{
//	ft_putstr("size = ");
//	ft_putnbr(block->size);
//	ft_putchar('\n');
//	ft_putstr("next = ");
//	ft_putnbr((int)block->next);
//	ft_putchar('\n');
//	ft_putstr("free = ");
//	ft_putnbr(block->free);
//	ft_putchar('\n');
	if (!block)
		return ;
	if (free_list_is_empty(free_list))
	{
		*free_list = block;
		return ;
	}
	block->next = *free_list;
	*free_list = block;
}
