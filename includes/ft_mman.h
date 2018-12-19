/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 09:37:40 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/19 12:50:22 by pdeguing         ###   ########.fr       */
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

# include <sys/mman.h>
# include <sys/resource.h>
# include <libft.h>

# define ALIGNMENT			16
# define ALIGN(size)		(((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))
# define HEADER_SIZE		(ALIGN(sizeof(size_t)))

# define ALLOCATED			1
# define FREE				~1L

# define TINY				48
# define SMALL				1024


void						*g_heap;


void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						*calloc(size_t count, size_t size);

void						show_alloc_mem(void);

#endif
