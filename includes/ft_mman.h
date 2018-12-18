/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:37:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/18 14:47:28 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H
# define FT_MMAN_H

# define BLACK				"\x1b[1m"
# define BLUE				"\x1b[0;34m"
# define RED				"\x1b[1;31m"
# define PINK				"\x1b[1;35m"
# define WHITE				"\x1b[1;37m"
# define RESET				"\x1b[0m"

# include <stdlib.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <libft.h>

# define META_SIZE			16

# define TINY				16	
# define SMALL				1024

typedef struct s_metadata	t_metadata;

struct						s_metadata
{
	size_t					size;
	t_metadata				*next;
	int						free;
};

t_metadata					*g_free_list;

void						*request_memory(size_t size);

int							free_list_is_empty(t_metadata **free_list);
void						*free_list_pop(t_metadata **free_list, size_t size);
void						free_list_push(t_metadata **free_list, t_metadata *block);

void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);

void						show_alloc_mem(void);

#endif
