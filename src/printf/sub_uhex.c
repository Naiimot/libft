/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_uhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:38:29 by tdelabro          #+#    #+#             */
/*   Updated: 2020/11/13 13:46:47 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

/*
** Function to print integers as unsigned hexadecimals.
*/

static int	ft_getuhex(uintmax_t n, char *buff, int len, t_format *format)
{
	int		ret;
	int		tmp;
	int		lenbis;
	char	rev[len];

	ret = 0;
	if (n == 0)
		ret += ft_buff(buff, '0', 0);
	else
	{
		lenbis = len;
		while (n != 0)
		{
			tmp = n % 16;
			if (format->conversion == 'x')
				rev[--lenbis] = (tmp < 10) ? tmp + '0' : tmp - 10 + 'a';
			else
				rev[--lenbis] = (tmp < 10) ? tmp + '0' : tmp - 10 + 'A';
			n = n / 16;
		}
		while (lenbis < len)
			ret += ft_buff(buff, rev[lenbis++], 0);
	}
	return (ret);
}

int			ft_sub_uhex(t_format *format, va_list args, char *buff)
{
	uintmax_t	num;
	int			ret;
	int			len;
	int			tmp;

	ret = 0;
	num = ft_lenmod_u(format->len_mod, args);
	len = ft_get_len_uhex(num, format);
	format->f_zero = (format->f_zero == 1 && format->f_left == 0\
			&& format->f_prec == 0) ? 1 : 0;
	format->f_hash = (format->f_hash == TRUE && num != 0) ? 1 : 0;
	tmp = (format->f_prec == TRUE && format->precision > len)\
			? format->precision : len;
	ret += ft_pre_printing_uhex(format, len, buff, tmp);
	if (!(num == 0 && format->f_prec == TRUE && format->precision == 0))
		ret += ft_getuhex(num, buff, len, format);
	if (format->f_left == TRUE)
		while (ret < format->field_width)
			ret += ft_buff(buff, ' ', 0);
	return (ret);
}
