/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:34:09 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 20:33:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

void		free(void *ptr)
{
	t_zone	*zone;

	zone = get_zone(ptr);
	if (!zone)
	{
		return ;
	}
	free_zone_free_list_add(zone, ptr);
	//if (zone->free_size == zone->size - T_ZONE_SIZE)
	//	munmap(zone, zone->size);
}
