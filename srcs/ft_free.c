/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:34:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 12:25:35 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		free(void *ptr)
{
	t_zone	*zone;

	//_PUTSTR_(BLUE"free: in"RESET);
	zone = get_zone(ptr);
	if (!zone)
	{
		//_PUTSTR_(BLUE"free: out"RESET);
		return ;
	}
	free_zone_free_list_add(zone, ptr);
	//if (zone->free_size == zone->size - T_ZONE_SIZE)
	//	free_zone_unmap(zone);
	//_PUTSTR_(BLUE"free: out"RESET);
}
