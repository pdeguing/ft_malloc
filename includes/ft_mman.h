/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:37:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 16:24:44 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H
# define FT_MMAN_H

# include <stdlib.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <libft.h>

# define CLASS_TOTAL		3
# define INDEX_LARGE		2
# define LARGE_META			32

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

typedef struct s_large		t_large;

struct						s_large
{
	size_t					size;
	void					*ptr;
};

typedef struct s_span		t_span;

struct						s_span
{
	void					*data;
	t_span					*next;
};

t_span						*g_cache[CLASS_TOTAL];

void						*large_object(size_t size);

void						*cache_pull(int index);
void						*cache_pull_large(size_t size);
void						cache_push_object(void *ptr, t_span *span);
void						cache_push_span(t_span *span, int index);

t_span						*span_create(size_t size);

//void						free(void *ptr);
void						*malloc(size_t size);
//void						*realloc(void *ptr, size_t size);

void						show_alloc_mem(void);

#endif
