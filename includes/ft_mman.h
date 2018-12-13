/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:37:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/13 09:53:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H
# define FT_MMAN_H

# include <stdlib.h>
# include <sys/mman.h>
# include <libft.h>

# define CLASS_TOTAL		3

enum e_class
{
	TINY	= 8,
	SMALL	= 1024,
	LARGE
};

typedef struct s_obj		t_obj;

struct						t_obj
{
	t_obj					*next;
};

t_obj						*g_cache[CLASS_TOTAL];

void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);

void						show_alloc_mem(void);

#endif
