/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:07:12 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/21 20:33:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_mman.h>

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
	str = realloc(str, size * 100);
	//ft_putendl(str);
	free(str);
}

int		main(void)
{
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"basic_malloc()"RESET);
	ft_putchar('\n');
	basic_malloc(100 * 16 * 1024 * 1024);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"basic_malloc()"RESET);
	ft_putchar('\n');
	basic_malloc(2);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putendl("--------------------------------------------------");
	ft_putendl(RED"basic_malloc()"RESET);
	ft_putchar('\n');
	basic_malloc(32);
	ft_putchar('\n');
	show_alloc_mem();
	return (0);
}
