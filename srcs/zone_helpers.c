/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:41:16 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/20 11:39:39 by pdeguing         ###   ########.fr       */
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

int		get_zone_list_index(size_t size)
{
	if (IS_TINY(size))
		return (INDEX_TINY);
	else if (IS_SMALL(size))
		return (INDEX_SMALL);
	return (INDEX_LARGE);
}

