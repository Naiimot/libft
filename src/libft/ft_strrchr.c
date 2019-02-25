/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:41:01 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/09 18:51:22 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;

	pos = -1;
	i = 0;
	if ((char)c == '\0')
		return (&((char*)s)[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if (pos == -1)
		return (NULL);
	else
		return (&((char*)s)[pos]);
}
