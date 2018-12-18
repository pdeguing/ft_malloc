# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 11:01:28 by pdeguing          #+#    #+#              #
#    Updated: 2018/12/18 08:40:10 by pdeguing         ###   ########.fr        #
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


ALL				:= ft_malloc.c ft_free.c ft_realloc.c\
					memory.c free_list.c

SRCS			:= $(addprefix $(SRCDIR)/, $(ALL))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@ cd libft/ && make

$(NAME):
	@ gcc $(CFLAGS) -shared -o $@ $(INCLUDES) $(LIBFT) $(SRCS)
	@ ln -sf $@ libft_malloc.so

clean:
	@ /bin/rm -rf $(OBJDIR)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f libft_malloc.so
	@ cd libft/ && make fclean

re: fclean all

norm:
	@ norminette *.c *.h

.PHONY:
	clean fclean all re
