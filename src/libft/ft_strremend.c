/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:13:27 by tdelabro          #+#    #+#             */
/*   Updated: 2019/01/25 19:35:09 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int		ft_strremend(char *str, int size)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (i < size - c)
	{
		if (str[i] == '\0' && i != size)
		{
			str[i] = ' ';
			j = i - 1;
			c++;
			while (++j < size - c)
				str[j] = str[1 + j];
		}
		i++;
	}
	str[size - c] = '\0';
	return (size - c);
}
