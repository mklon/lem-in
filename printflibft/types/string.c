/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:05:06 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 16:05:07 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		string_type(t_base *a, va_list *arg_list, int str_len)
{
	char	*str_arg;

	if (a->ll || a->l)
		return (wstring_type(a, arg_list, 0));
	str_arg = va_arg(*arg_list, char*);
	str_arg = (!str_arg) ? "(null)" : str_arg;
	if ((a->precision && (int)ft_strlen(str_arg) > a->precision)
		|| (!a->precision && a->p_mod))
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
