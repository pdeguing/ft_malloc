/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:02:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 17:15:32 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_mman.h>

#define BLACK				"\x1b[1m"
#define BLUE				"\x1b[0;34m"
#define RED					"\x1b[1;31m"
#define PINK				"\x1b[1;35m"
#define WHITE				"\x1b[1;37m"
#define RESET				"\x1b[0m"

void	basic_malloc(int size)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * size);	
	if (!str)
	{
		ft_putendl("str = NULL");
		return ;
	}
	i = 0;
	while (i < size - 1)
	{
		str[i] = 'X';
		i++;
	}
	str[i] = '\0';
	ft_putstr("str = ");
	ft_putendl(str);
}

void	test_span(void)
{
	t_span	*span;

	span = span_create(8);
	if (!span->next)
		ft_putendl("span->next == NULL");
}

int		main(void)
{
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"getpagesize()"RESET);
	ft_putchar('\n');
	ft_putnbr(getpagesize());
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"test_span()"RESET);
	ft_putchar('\n');
	test_span();
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"basic_malloc()"RESET);
	ft_putchar('\n');
	basic_malloc(5);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"basic_malloc()"RESET);
	ft_putchar('\n');
	basic_malloc(32);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"basic_malloc()"RESET);
	ft_putchar('\n');
	basic_malloc(32);
	ft_putchar('\n');
	return (0);
}
