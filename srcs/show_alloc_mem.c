/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:08:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 13:28:33 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		show_alloc_mem(void)
{
	t_metadata	*head;

	head = g_free_list;
	ft_printf("memory state:\n");
	while (head)
	{
		ft_printf("%p - %p : %10d bytes (%d)\n", head + 1, (char *)head + head->size, head->size, head->free);
		head = head->next;
	}
}
