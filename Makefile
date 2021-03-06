# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 11:01:28 by pdeguing          #+#    #+#              #
#    Updated: 2018/12/22 12:30:08 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE	:= $(shell uname -m)_$(shell uname -s)
endif

NAME			:= libft_malloc_$(HOSTTYPE).so
SRCDIR			:= srcs

INCLUDES		:= -I ./includes/ -I ./libft/includes/
LIBFT			:= libft/libft.a

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror


ALL				:= ft_malloc.c ft_free.c ft_realloc.c show_alloc_mem.c\
					malloc_zone.c free_zone.c zone_helpers.c malloc_zone_defrag.c\
					ft_calloc.c

SRCS			:= $(addprefix $(SRCDIR)/, $(ALL))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@ git clone https://github.com/pdeguing/libft.git
	@ cd libft/ && make

$(NAME):
	@ gcc $(CFLAGS) -shared -o $@ $(INCLUDES) $(LIBFT) $(SRCS)
	@ ln -sf $@ libft_malloc.so

test: $(LIBFT)
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test_main.c -o test_main
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test0.c -o test0
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test1.c -o test1
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test2.c -o test2
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test3.c -o test3
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test4.c -o test4
	@ $(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRCS) test5.c -o test5

clean:
	@ /bin/rm -rf $(OBJDIR)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f libft_malloc.so
	@ /bin/rm -f test_main
	@ /bin/rm -rf libft

re: fclean all

norm:
	@ norminette *.c *.h

.PHONY:
	clean fclean all re
