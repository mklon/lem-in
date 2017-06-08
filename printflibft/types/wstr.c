/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:27:00 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/15 12:27:01 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		g_temp;

int		uni_size(int i)
{
	if (i == 0)
		return (0);
	else if (i < 128)
		return (1);
	else if (i < 2048)
		return (2);
	else
		return (3);
}

int		count_length(char **mass)
{
	int		len;

	len = 0;
	while (**mass)
	{
		len += ft_strlen(*mass);
		mass++;
	}
	return (len);
}

int		put_n_double(int length, int *mass, int f)
{
	int		put_len;

	put_len = 0;
	while (length >= uni_size(*mass) && *mass)
	{
		if (f)
			ft_putstr(wchar_convert(*mass));
		length -= uni_size(*mass);
		put_len += uni_size(*mass);
		mass++;
	}
	return (put_len);
}

int		put_unicode(char **str, t_base *arg_base, int *mass, int i)
{
	int		str_len;
	int		res;

	if (arg_base->precision)
		str_len = arg_base->precision;
	else
		str_len = count_length(str);
	str_len = str_len < 0 ? 0 : str_len;
	res = put_n_double(str_len, mass, 0);
	if (str_len > res && arg_base->wight >= arg_base->precision)
		i += str_len - res;
	if (arg_base->flag_hyphen)
	{
		res = put_n_double(str_len, mass, 1);
		ft_putnchr(' ', arg_base->wight - str_len + i);
	}
	else
	{
		ft_putnchr(arg_base->flag_zero ? '0' : ' ',
			arg_base->wight - str_len + i);
		res = put_n_double(str_len, mass, 1);
	}
	res += (arg_base->wight - str_len) > 0 ? arg_base->wight - str_len : 0;
	return (res + i);
}

int		wstring_type(t_base *arg_base, va_list *arg_list, int i)
{
	int		dop;
	int		*mass;
	int		*tmp;
	char	**str;

	mass = va_arg(*arg_list, int*);
	if (mass == NULL)
		return (print_null(arg_base));
	tmp = mass;
	while (mass[i])
		i++;
	str = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	str[i++] = wchar_convert(*mass);
	while (*mass > 0 && *str[i - 1])
		str[i++] = wchar_convert(*(++mass));
	dop = put_unicode(str, arg_base, tmp, 0);
	g_temp = count_length(str);
	while (--i >= 0)
		free(str[i]);
	free(str);
	if (arg_base->wight > g_temp)
		return (arg_base->wight);
	return (dop);
}
