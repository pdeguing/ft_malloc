/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:02:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/15 12:37:37 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_mman.h>

void	basic_malloc(void)
{
	char	*str;
	int		i;

	ft_putstr("malloc[");
	str = (char *)malloc(sizeof(char) * 5);	
	ft_putstr("]\n");
	if (!str)
	{
		ft_putendl("str = NULL");
		return ;
	}
	i = 0;
	while (i < 4)
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
	ft_putstr("getpagesize() = ");
	ft_putnbr(getpagesize());
	ft_putchar('\n');
	ft_putendl("test_span()");
	test_span();
	ft_putendl("basic_malloc():");
	basic_malloc();
	return (0);
}
