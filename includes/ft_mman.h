/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:37:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/22 15:32:07 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MMAN_H
# define FT_MMAN_H

# define BLACK					"\x1b[1m"
# define BLUE					"\x1b[0;34m"
# define RED					"\x1b[0;31m"
# define GREEN					"\x1b[0;32m"
# define PINK					"\x1b[1;35m"
# define WHITE					"\x1b[1;37m"
# define RESET					"\x1b[0m"

# include <sys/mman.h>
# include <sys/resource.h>
# include <libft.h>

# define _PUTSTR_(str)			ft_putendl_fd(str, 2);

# define _PUTZONE_(zone)		print_zone(zone);
# define _PUTFREE_(list)		print_free_list(list);

# define MIN(a, b)				((a > b) ? b : a)

# define ALIGN_DFT				8
# define ALIGN_TINY				16
# define ALIGN_SMALL			512
# define ALIGN_PAGE				4096

# define ALIGN(align, size)		(((size) + (align - 1)) & ~(align - 1))
# define T_ZONE_SIZE			(ALIGN(ALIGN_DFT, sizeof(t_zone)))
# define T_FREE_SIZE			(ALIGN(ALIGN_DFT, sizeof(t_free)))
# define SIZE_T_SIZE			(ALIGN(ALIGN_DFT, sizeof(size_t)))
# define PAGE_SIZE				(ALIGN_PAGE)

# define BIT_ALLOC				1
# define BIT_FREE				~1L

# define IS_TINY(size)			(0 <= size && size <= 992)
# define IS_SMALL(size)			(993 <= size && size <= 131040)
# define IS_LARGE(size)			(size >= 131040)

# define ZONE_TINY				(ALIGN_TINY * PAGE_SIZE * 32)
# define ZONE_SMALL				(ALIGN_SMALL * PAGE_SIZE * 8)
# define ZONE_LARGE(size)		(ALIGN(ALIGN_PAGE, size))

typedef struct s_zone			t_zone;
typedef struct s_free			t_free;

struct							s_free
{
	size_t						size;
	t_free						*next;
};

struct							s_zone
{
	size_t						size;
	size_t						free_size;
	t_free						*list;
	t_zone						*next;
};

# define INDEX_TINY				0
# define INDEX_SMALL			1
# define INDEX_LARGE			2

# define INDEX_CMP(a, b)		(get_index(a & BIT_FREE) == get_index(b))

t_zone							*g_zone_list[3];

size_t							get_zone_size(size_t size);
int								get_index(size_t size);
t_zone							*get_zone(void *ptr);

size_t							align_request_size(size_t size);

void							*malloc_zone_request_block(size_t request_size);
void							malloc_zone_defrag(t_free *block);
void							*malloc_zone_free_list_retrieve(t_zone *zone,
		t_free *free_block, t_free *prev_block, size_t request_size);

void							free_zone_free_list_add(t_zone *zone,
		void *ptr);

void							free(void *ptr);
void							*malloc(size_t size);
void							*realloc(void *ptr, size_t size);
void							*calloc(size_t count, size_t size);

void							show_alloc_mem(void);

/*
**	DEBUG
*/

void							print_zone(t_zone *zone);
void							print_free_list(t_free *block);

#endif
