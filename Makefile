# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 11:01:28 by pdeguing          #+#    #+#              #
#    Updated: 2018/12/12 12:44:56 by pdeguing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE	:= $(shell uname -m)_$(shell uname -s)
endif

NAME			= libft_malloc_$(HOSTTYPE).so

CFLAGS			= -Wall -Wextra -Werror

SRCS			= ft_malloc.c ft_free.c ft_realloc.c

LIBFT			= libft/libft.a

all: $(NAME)

$(NAME): cmp
	@ ar rcs $(NAME) *.o
	@ ranlib $(NAME)
	@ ln -sf $(NAME) libft_malloc.so

$(LIBFT):
	@ cd libft/ && make

cmp:
	@ gcc -c $(CFLAGS) $(SRCS) $(LIBFT)

clean:
	@ /bin/rm -f *.o

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

norm:
	@ norminette *.c *.h

.PHONY:
	clean fclean all re
