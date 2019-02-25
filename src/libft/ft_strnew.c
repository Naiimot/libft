/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:01:50 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/09 22:49:26 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (1 + size--)
		str[1 + size] = '\0';
	return (str);
}
