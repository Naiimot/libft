/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:46:57 by tdelabro          #+#    #+#             */
/*   Updated: 2020/11/14 14:37:21 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

/*
** This function return the number of characters wich form the next segment of
** the string to be process.
*/

size_t			ft_size_word(const char *str)
{
	size_t	c;

	c = 0;
	if (str[c] == '%')
	{
		if (str[1] == '%')
			return (2);
		else
		{
			while (str[++c])
				if (ft_memchr("0123456789*#- +.hlLjz", str[c],\
							sizeof("0123456789*#- +.hlLjz")) == NULL)
				{
					c++;
					break ;
				}
		}
	}
	else
		while (str[c] && str[c] != '%')
			c++;
	return (c);
}

/*
** Those three functions fill the struct t_format with every information we need
** to do the conversion.
*/

static void		ft_init_lenmod(t_format *format, unsigned char i)
{
	if ((format->buffer)[i] == 'h' && (format->buffer)[i + 1] == 'h')
		format->len_mod = hh;
	else if ((format->buffer)[i] == 'h')
		format->len_mod = h;
	else if ((format->buffer)[i] == 'l' && (format->buffer)[i + 1] == 'l')
		format->len_mod = ll;
	else if ((format->buffer)[i] == 'l')
		format->len_mod = l;
	else if ((format->buffer)[i] == 'L')
		format->len_mod = L;
	else if ((format->buffer)[i] == 'j')
		format->len_mod = j;
	else if ((format->buffer)[i] == 'z')
		format->len_mod = z;
	else
		format->len_mod = none;
}

static void		ft_init_prec(t_format *format, unsigned char i, va_list args)
{
	format->precision = (format->conversion == 'f' || \
			format->conversion == 'e') ? 6 : 0;
	if ((format->buffer)[i] == '.' && (format->f_prec = 1))
	{
		if (format->buffer[i + 1] == '*' && (i += 2))
		{
			format->precision = (int)va_arg(args, int);
			if ((format->conversion == 'f' || format->conversion == 'e')\
					&& format->precision < 0)
				format->precision = 6;
			(format->precision < 0) ? format->f_prec = 0 : 1;
		}
		else
		{
			format->precision = ft_ptf_atoi(&(format->buffer)[++i], format, 1);
			while ((format->buffer)[i] >= '0' && (format->buffer)[i] <= '9')
				i++;
		}
	}
	ft_init_lenmod(format, i);
}

static void		ft_fill_format(t_format *format, va_list args)
{
	unsigned char	i;

	i = 0;
	format->conversion = format->buffer[format->buf_size - 2];
	while (ft_memchr("#0- +", format->buffer[++i], sizeof("#0- +")) != NULL)
	{
		format->f_hash = format->buffer[i] == '#' || format->f_hash;
		format->f_zero = format->buffer[i] == '0' || format->f_zero;
		format->f_left = format->buffer[i] == '-' || format->f_left;
		format->f_space = format->buffer[i] == ' ' || format->f_space;
		format->f_sign = format->buffer[i] == '+' || format->f_sign;
	}
	if (format->buffer[i] == '*'\
			&& (format->field_width = (int)va_arg(args, int)))
	{
		if (format->field_width < 0 && (format->f_left = 1))
			format->field_width *= -1;
	}
	else if (format->buffer[i] <= '9' && format->buffer[i] >= '1')
		format->field_width = ft_ptf_atoi(&format->buffer[i], format, FALSE);
	while (format->buffer[i] && ft_memchr(".lLhjzcspdiouxXfeb%",\
				format->buffer[i], sizeof(".lLhjzcspdiouxXfeb%")) == NULL)
		i++;
	ft_init_prec(format, i, args);
}

/*
 ** Structure t_format creation + all flags to 0 + fill buffer with the segment
 ** and buff_size with its size.
*/

t_format		*ft_iniformat(const char *str, size_t s, va_list args)
{
	t_format	*format;

	if (!(format = (t_format*)malloc(sizeof(t_format))))
		return (NULL);
	if (!(format->buffer = (char*)malloc(sizeof(char) * (s + 1))))
	{
		free(format);
		return (NULL);
	}
	ft_memmove(format->buffer, str, s);
	(format->buffer)[s] = '\0';
	format->buf_size = s + 1;
	ft_formattozero(format);
	if ((format->buffer)[0] == '%')
		ft_fill_format(format, args);
	else
		format->conversion = '\0';
	return (format);
}
