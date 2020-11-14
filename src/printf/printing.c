/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:24:46 by tdelabro          #+#    #+#             */
/*   Updated: 2020/11/14 14:06:28 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

/*
** All these function handle the printing of character before the real output,
** based on field width, precision, flags(#+- 0).
** Each one have a sligthy different functionment but the architecture remains.
** Shared subfunctions can be find in the printing_complement.c file.
*/

int	ft_pre_printing_dec(t_format *fmt, int len, char *buff, t_bool sign)
{
	int		ret;
	t_bool	mod;
	int		tmp;

	ret = 0;
	fmt->f_zero = (fmt->f_zero && !fmt->f_left && !fmt->f_prec) ? 1 : 0;
	mod = (sign || fmt->f_sign || fmt->f_space) ? 1 : 0;
	tmp = (fmt->f_prec && fmt->precision > len) ? fmt->precision : len;
	if (fmt->f_zero == TRUE || fmt->f_left == TRUE)
	{
		ret += ft_mod(fmt, buff, sign);
		if (fmt->f_zero == TRUE)
			ret = padd(fmt->field_width - tmp, ret, buff, '0');
	}
	else
	{
		ret = padd(fmt->field_width - tmp - (int)mod, ret, buff, ' ');
		if (fmt->f_zero == FALSE)
			ret += ft_mod(fmt, buff, sign);
	}
	ret += ft_endzero(fmt, len, buff, tmp);
	return (ret);
}

int	ft_pre_printing_float(t_format *fmt, int len, t_bool sign)
{
	int		ret;
	t_bool	mod;
	int		tmp;
	char	buff[PFBUF];

	ret = 0;
	fmt->f_zero = (fmt->f_zero && !fmt->f_left) ? 1 : 0;
	mod = (sign || fmt->f_sign || fmt->f_space) ? 1 : 0;
	tmp = (fmt->f_prec && fmt->precision > len) ? fmt->precision : len;
	if (fmt->f_zero == TRUE || fmt->f_left == TRUE)
	{
		ret += ft_mod(fmt, buff, sign);
		if (fmt->f_zero == TRUE)
			ret = padd(fmt->field_width - tmp, ret, buff, '0');
	}
	else
	{
		ret = padd(fmt->field_width - tmp - (int)mod, ret, buff, ' ');
		if (fmt->f_zero == FALSE)
			ret += ft_mod(fmt, buff, sign);
	}
	ret += ft_endzero(fmt, len, buff, tmp);
	ft_buff(buff, '0', 1);
	return (ret);
}

int	ft_pre_printing_add(t_format *fmt, int len, char *buff)
{
	int		ret;
	int		tmp;

	ret = 0;
	fmt->f_zero = (fmt->f_zero == 1 && fmt->f_left == 0 && fmt->f_prec == 0);
	tmp = (fmt->f_prec == TRUE && fmt->precision > len) ? fmt->precision : len;
	if (fmt->f_zero == TRUE || fmt->f_left == TRUE)
	{
		ret += ft_buff(buff, '0', 0);
		ret += ft_buff(buff, 'x', 0);
		if (fmt->f_zero == TRUE)
			ret = padd(fmt->field_width - tmp, ret, buff, '0');
	}
	else
	{
		ret = padd(fmt->field_width - tmp - 2, ret, buff, ' ');
		ret += ft_buff(buff, '0', 0);
		ret += ft_buff(buff, 'x', 0);
	}
	ret += ft_endzero(fmt, len, buff, tmp);
	return (ret);
}

int	ft_pre_printing_uhex(t_format *fmt, int len, char *buff, int tmp)
{
	int	ret;

	ret = 0;
	if (fmt->f_zero == TRUE || fmt->f_left == TRUE)
	{
		if (fmt->f_hash == TRUE)
		{
			ret += ft_buff(buff, '0', 0);
			ret += ft_buff(buff, fmt->conversion, 0);
		}
		if (fmt->f_zero == TRUE)
			ret = padd(fmt->field_width - tmp, ret, buff, '0');
	}
	else
	{
		ret = padd(fmt->field_width - tmp - (fmt->f_hash * 2), ret, buff, ' ');
		if (fmt->f_hash == TRUE)
		{
			ret += ft_buff(buff, '0', 0);
			ret += ft_buff(buff, fmt->conversion, 0);
		}
	}
	ret += ft_endzero(fmt, len, buff, tmp);
	return (ret);
}

int	ft_pre_printing_uoct(t_format *fmt, int len, char *buff, int tmp)
{
	int ret;

	ret = 0;
	if (fmt->f_zero == TRUE || fmt->f_left == TRUE)
	{
		if (fmt->f_hash == TRUE)
			ret += ft_buff(buff, '0', 0);
		if (fmt->f_zero == TRUE)
			ret = padd(fmt->field_width - tmp, ret, buff, '0');
	}
	else
	{
		ret = padd(fmt->field_width - tmp - (int)fmt->f_hash, ret, buff, ' ');
		if (fmt->f_hash == TRUE)
			ret += ft_buff(buff, '0', 0);
	}
	ret += ft_endzero(fmt, len, buff, tmp);
	return (ret);
}
