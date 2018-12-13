/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:02:23 by pdeguing          #+#    #+#             */
/*   Updated: 2018/12/13 11:15:13 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		main(void)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * 5);	
	if (!str)
	{
		ft_printf("str = NULL\n");
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		str[i] = 'X';
		i++;
	}
	str[i] = '\0';
	ft_printf("str = %s\n", str);
	return (0);
}
