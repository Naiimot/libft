/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenint_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:25:13 by tdelabro          #+#    #+#             */
/*   Updated: 2019/02/18 16:06:12 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short	ft_lenint_base(int n, unsigned short const b)
{
	unsigned short	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / b;
		len++;
	}
	return (len);
}
