/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:02:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/13 14:10:26 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		main(void)
{
	char	*str;
	int		i;

	ft_putstr("malloc[");
	str = (char *)malloc(sizeof(char) * 5);	
	ft_putstr("]\n");
	if (!str)
	{
		ft_putendl("str = NULL");
		return (0);
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
	return (0);
}
