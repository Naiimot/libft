/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:31:22 by tdelabro          #+#    #+#             */
/*   Updated: 2019/05/25 22:11:12 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		write(fd, s, i);
	}
}
