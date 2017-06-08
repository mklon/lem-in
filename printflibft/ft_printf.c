/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:40:28 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 14:40:30 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zeroing_structure(t_base *arg_base)
{
	arg_base->flag_hyphen = 0;
	arg_base->flag_plus = 0;
	arg_base->flag_space = 0;
	arg_base->flag_sharp = 0;
	arg_base->flag_zero = 0;
	arg_base->wight = 0;
	arg_base->precision = 0;
	arg_base->p_mod = 0;
	arg_base->l = 0;
	arg_base->ll = 0;
	arg_base->h = 0;
	arg_base->hh = 0;
	arg_base->j = 0;
	arg_base->z = 0;
	return (1);
}

int		qualifier_search(char **format)
{
	if (**format == '-' || **format == '+' || **format == '#' || **format == ' '
		|| **format == '.' || **format == '*' || **format == 'l'
		|| **format == 'h' || **format == 'z' || **format == 'j'
		|| (**format >= '0' && **format <= '9'))
		return (1);
	return (0);
}

int		qualifier_def(char **format, t_base *arg_base, va_list *arg_list)
{
	int		i;
	int		byte_amount;

	i = 1;
	if (!*(++*format))
		return (0);
	while ((i && **format == '%') || qualifier_search(format))
	{
		i = 0;
		if (!(qualifier_flags(format, arg_base)))
			return (-1);
		if (!(qualifier_wight(format, arg_base, arg_list, 0)))
			return (-1);
		if (!(qualifier_precision(format, arg_base, arg_list)))
			return (-1);
		if (!(qualifier_lenght(format, arg_base)))
			return (-1);
		if (!**format)
			return (0);
	}
	byte_amount = qualifier_type_one(format, arg_base, arg_list);
	(*format)++;
	return (byte_amount);
}

int		ft_printf_body(char *format, va_list *arg_list, int byte_amount)
{
	int		qual_ize;
	char	*next_arg;
	t_base	arg_base;

	next_arg = ft_strchr(format, '%');
	if (!*format)
		return (byte_amount);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (byte_amount + (int)ft_strlen(format));
	}
	else if (format == next_arg && zeroing_structure(&arg_base))
	{
		if ((qual_ize = qualifier_def(&format, &arg_base, arg_list)) == -1)
			return (-1);
		else
			return (ft_printf_body(format, arg_list, byte_amount + qual_ize));
	}
	else
	{
		ft_putnstr(format, next_arg - format);
		return (ft_printf_body(format + (next_arg - format),
				arg_list, byte_amount + (next_arg - format)));
	}
}

int		ft_printf(char *format, ...)
{
	int		byte_amount;
	va_list	arg_list;

	va_start(arg_list, format);
	byte_amount = ft_printf_body(format, &arg_list, 0);
	return (byte_amount);
}
