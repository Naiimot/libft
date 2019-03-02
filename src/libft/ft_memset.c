/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:23:05 by tdelabro          #+#    #+#             */
/*   Updated: 2019/03/02 20:58:49 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	if (b)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char*)b)[i] = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
