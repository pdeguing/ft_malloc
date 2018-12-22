/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:41:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/22 15:24:52 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mman.h>

size_t	get_zone_size(size_t size)
{
	if (IS_TINY(size))
		return (ZONE_TINY);
	else if (IS_SMALL(size))
		return (ZONE_SMALL);
	return (ZONE_LARGE(size));
}

int		get_index(size_t size)
{
	if (IS_TINY(size))
		return (INDEX_TINY);
	else if (IS_SMALL(size))
		return (INDEX_SMALL);
	return (INDEX_LARGE);
}

t_zone	*get_zone(void *ptr)
{
	t_zone	*zone;
	int		i;
	t_free	*block;
	size_t	count;

	i = 0;
	while (i < 3)
	{
		zone = g_zone_list[i];
		while (zone)
		{
			count = T_ZONE_SIZE;
			block = (t_free *)((char *)zone + T_ZONE_SIZE);
			while (count < zone->size)
			{
				if ((void *)((char *)block + SIZE_T_SIZE) == ptr)
					return (zone);
				count += (block->size & BIT_FREE);
				block = (t_free *)((char *)block + (block->size & BIT_FREE));
			}
			zone = zone->next;
		}
		i++;
	}
	return (NULL);
}
