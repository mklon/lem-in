/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:14:55 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 16:14:56 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*wchar_convert(int i)
{
	unsigned char	*str;

	str = (unsigned char*)ft_strnew(3);
	if (i < 128)
		*str = i;
	else if (i < 2048)
	{
		str[0] = (i >> 6) + 192;
		str[1] = i << 2;
		str[1] = (str[1] >> 2) + 128;
	}
	else if (i > 2048)
	{
		str[0] = (i >> 12) + 224;
		str[1] = i >> 6;
		str[1] = str[1] << 2;
		str[1] = str[1] >> 2;
		str[1] += 128;
		str[2] = i << 2;
		str[2] = (str[2] >> 2) + 128;
	}
	return ((char *)str);
}

int		wcharacter_type(t_base *arg_base, va_list *arg_list)
{
	int		i;
	int		chr_arg;
	char	*str;

	str = NULL;
	chr_arg = va_arg(*arg_list, int);
	i = uni_size(chr_arg);
	if (arg_base->flag_hyphen)
	{
		str = wchar_convert(chr_arg);
		(i == 0 && chr_arg == 0) ? ft_putchar('\0')
		: ft_putstr(str);
		ft_putnchr(' ', arg_base->wight
		- ((i == 0 && chr_arg == 0) ? 1 : i));
	}
	else
	{
		ft_putnchr(arg_base->flag_zero ? '0' : ' ', arg_base->wight
		- ((i == 0 && chr_arg == 0) ? 1 : i));
		str = wchar_convert(chr_arg);
		(i == 0 && chr_arg == 0) ? ft_putchar('\0') : ft_putstr(str);
	}
	free(str);
	i = (i == 0) ? i + 1 : i;
	return (arg_base->wight ? arg_base->wight : i);
}
