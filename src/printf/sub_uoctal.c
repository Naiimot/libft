/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_uoctal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:44:54 by tdelabro          #+#    #+#             */
/*   Updated: 2020/11/13 13:47:26 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

/*
** Function to print integers as unsigned octal.
*/

static int	ft_getuoct(uintmax_t n, char *buff, int len)
{
	int		ret;
	int		lenbis;
	char	rev[len];

	if (len == 0)
		return (0);
	ret = 0;
	if (n == 0)
		ret += ft_buff(buff, '0', 0);
	else
	{
		lenbis = len;
		while (n != 0)
		{
			rev[--lenbis] = (n % 8) + '0';
			n = n / 8;
		}
		while (lenbis < len)
			ret += ft_buff(buff, rev[lenbis++], 0);
	}
	return (ret);
}

static int	ft_get_len_uoct(uintmax_t num, t_format *format)
{
	int			len;

	if (num == 0 && !(format->f_prec == TRUE && format->precision == 0))
		return (1);
	len = 0;
	while ((num != 0) && (++len))
		num = num / 8;
	return (len);
}

int			ft_sub_uoctal(t_format *format, va_list args, char *buff)
{
	uintmax_t	num;
	int			ret;
	int			len;
	int			tmp;

	ret = 0;
	num = ft_lenmod_u(format->len_mod, args);
	len = ft_get_len_uoct(num, format);
	(num == 0 && !(format->f_prec == 1 && format->precision == 0))\
			? format->f_hash = 0 : 1;
	format->f_zero = (format->f_zero == 1 && format->f_left == 0\
			&& format->f_prec == 0) ? 1 : 0;
	tmp = (format->f_prec == TRUE && format->precision > len)\
			? format->precision - format->f_hash : len;
	ret += ft_pre_printing_uoct(format, len, buff, tmp);
	if (!(!num && !format->f_hash && format->f_prec && !format->precision))
		ret += ft_getuoct(num, buff, len);
	if (format->f_left == TRUE)
		while (ret < format->field_width)
			ret += ft_buff(buff, ' ', 0);
	return (ret);
}
