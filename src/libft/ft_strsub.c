/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:31:28 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/10 14:42:03 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if ((sub = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (s)
	{
		sub[len] = '\0';
		while (len--)
			sub[len] = s[start + len];
	}
	return (sub);
}
