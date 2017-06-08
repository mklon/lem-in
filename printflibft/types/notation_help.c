/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notation_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:10:15 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/23 16:10:16 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	notation_helper(char **format, t_base *arg_base, char *str)
{
	int		base;

	base = (**format == 'o' || **format == 'O') ? 8 : 16;
	arg_base->precision = (arg_base->precision == -1 && **format != 'p')
	? 0 : arg_base->precision;
	if (arg_base->precision > 0)
		arg_base->flag_zero = 0;
	if (arg_base->wight > arg_base->precision
		&& arg_base->precision > (int)ft_strlen(str) && base == 8)
		arg_base->flag_sharp = 0;
	if (arg_base->flag_hyphen)
	{
		number_lenght(format, arg_base, 1, str);
		ft_putnchr('0', arg_base->precision - (unsigned int)ft_strlen(str));
		ft_putstr(str);
		ft_putnchr(' ', arg_base->wight -
		((arg_base->precision > (int)ft_strlen(str))
		? (unsigned int)arg_base->precision : (unsigned int)ft_strlen(str)));
	}
}

char	pointer_null(t_base *arg_base)
{
	if ((arg_base->wight <= 0 && arg_base->p_mod)
		|| (arg_base->wight > 0 && arg_base->precision == -1))
		return ('\0');
	return ('0');
}

char	notation_null(t_base *arg_base, char **format)
{
	if (((arg_base->wight <= 0 && arg_base->precision == -1) || arg_base->p_mod
		|| (arg_base->wight > 0 && arg_base->precision == -1))
		&& !((**format == 'o' || **format == 'O') && arg_base->flag_sharp))
	{
		arg_base->flag_sharp = 0;
		return ('\0');
	}
	return ('0');
}

int		not_result(int num_len, t_base *argbase, int i)
{
	int		tmp;
	int		minus;

	minus = (argbase->flag_sharp ? 1 : 0);
	if (i == 2)
		argbase->precision += 2;
	tmp = argbase->precision;
	if (argbase->wight + minus * i > argbase->precision)
		tmp = argbase->wight + minus * i;
	if (tmp >= num_len)
		return (tmp);
	return (num_len);
}

int		print_null(t_base *a)
{
	int		str_len;
	char	*str_arg;

	str_arg = "(null)";
	if (a->precision && (int)ft_strlen(str_arg) > a->precision)
		str_len = a->precision;
	else
		str_len = (int)ft_strlen(str_arg);
	a->precision = (!ft_strcmp(str_arg, "")) ? 0 : a->precision;
	str_len = (str_len < 0) ? 0 : str_len;
	if (a->flag_hyphen)
	{
		ft_putnstr(str_arg, str_len);
		ft_putnchr(' ', a->wight - str_len);
	}
	else
	{
		ft_putnchr(a->flag_zero ? '0' : ' ', a->wight - str_len);
		ft_putnstr(str_arg, str_len);
	}
	str_len = (!*str_arg ? 0 : str_len);
	return (a->wight > str_len ? a->wight : str_len);
}
