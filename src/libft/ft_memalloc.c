/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:15:22 by tdelabro          #+#    #+#             */
/*   Updated: 2019/02/23 12:36:05 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memalloc(size_t size)
{
	int *mem;

	if ((mem = (int*)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return ((void*)mem);
}
