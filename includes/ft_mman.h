/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:37:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/14 12:40:21 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H
# define FT_MMAN_H

# include <stdlib.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <libft.h>

# define CLASS_TOTAL		3

enum e_class
{
	TINY	= 8,
	SMALL	= 1024,
	LARGE
};

typedef struct s_obj		t_obj;

struct						s_obj
{
	t_obj					*next;
};

typedef struct s_span		t_span;

struct						s_span
{
	t_obj					*list;
	t_span					*next;
};

t_span						*g_cache[CLASS_TOTAL];

int							cache_check_availability(size_t size);
void						*cache_pull(size_t size);
void						cache_push_object(void *ptr, t_span span);
void						cache_push_span(t_span span, size_t size);

t_span						span_create(size_t size);

//void						free(void *ptr);
void						*malloc(size_t size);
//void						*realloc(void *ptr, size_t size);

void						show_alloc_mem(void);

#endif
