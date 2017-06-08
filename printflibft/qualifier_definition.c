/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qualifier_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:30:13 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/01 11:30:14 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*qualifier_flags(char **format, t_base *arg_base)
{
	if (**format == '0')
		arg_base->flag_zero = 1;
	else if (**format == '-')
	{
		arg_base->flag_hyphen = 1;
		arg_base->flag_zero = 0;
	}
	else if (**format == '+')
		arg_base->flag_plus = 1;
	else if (**format == ' ')
		arg_base->flag_space = 1;
	else if (**format == '#')
		arg_base->flag_sharp = 1;
	if (**format == '-' || **format == '+' || **format == '#'
		|| **format == '0' || **format == ' ')
	{
		++(*format);
		return (qualifier_flags(format, arg_base));
	}
	else
		return (*format);
}

char	*qualifier_wight(char **format, t_base *arg_base, va_list *arg_list,
						int digit)
{
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			arg_base->wight = va_arg(*arg_list, int);
			if (arg_base->wight < 0)
			{
				arg_base->flag_hyphen = 1;
				arg_base->wight *= -1;
			}
		}
		else if (ft_isdigit((int)(**format)))
		{
			while (ft_isdigit(**format))
				digit = digit * 10 + (*(*format)++ - '0');
			arg_base->wight = digit;
		}
		else
			return (*format);
	}
	return (*format);
}

char	*qualifier_precision(char **format, t_base *arg, va_list *arg_list)
{
	if (**format == '.')
	{
		arg->precision = -1;
		(*format)++;
		if (**format == '*')
		{
			arg->precision = 0;
			arg->precision = va_arg(*arg_list, int);
			if (arg->precision >= 0)
				arg->p_mod = 1;
			arg->precision = (arg->precision < 0) ? 0 : arg->precision;
			(*format)++;
		}
		else if (ft_isdigit((int)(**format)))
		{
			arg->p_mod = 1;
			arg->precision = 0;
			while (ft_isdigit((int)(**format)))
				arg->precision = arg->precision * 10
				+ (*(*format)++ - '0');
		}
		return (*format);
	}
	else
		return (*format);
}

int		space_lenght(char **format, t_base *arg_base)
{
	char	*str;

	str = *format;
	str++;
	while (*str == ' ')
		str++;
	if (*str == 'h' || *str == 'l')
	{
		if (*str == 'h')
			arg_base->hh = 1;
		if (*str == 'l')
			arg_base->ll = 1;
		*format = str;
		return (1);
	}
	return (0);
}

char	*qualifier_lenght(char **form, t_base *arg_base)
{
	if ((**form == 'h' || **form == 'l') && *(*form + 1) == ' ')
		if (space_lenght(form, arg_base) == 1)
			return (++(*form));
	if ((**form == 'l' && *(*form + 1) == 'l')
		|| ((**form == 'h' && *(*form + 1) == 'h')))
	{
		if (**form == 'l' && *(*form + 1) == 'l')
			arg_base->ll = 1;
		else if (**form == 'h' && *(*form + 1) == 'h')
			arg_base->hh = 1;
		++(*form);
		return (++(*form));
	}
	else if (**form == 'l')
		arg_base->l = 1;
	else if (**form == 'h')
		arg_base->h = 1;
	else if (**form == 'j')
		arg_base->j = 1;
	else if (**form == 'z')
		arg_base->z = 1;
	if (**form == 'z' || **form == 'j' || **form == 'h' || **form == 'l')
		++(*form);
	return (*form);
}
