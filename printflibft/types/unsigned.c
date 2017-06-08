/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:10:14 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 16:10:15 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long int	ft_get_number(char **format, t_base *arg_base,
					va_list *arg_list)
{
	unsigned long long int	number;

	number = va_arg(*arg_list, unsigned long long int);
	if (arg_base->j == 1 || arg_base->z == 1)
		return (number);
	else if (arg_base->ll == 1)
		return (number);
	else if (arg_base->l == 1 || **format == 'U')
		return ((unsigned long int)number);
	else if (arg_base->h == 1)
		return ((unsigned short int)number);
	else if (arg_base->hh == 1)
		return ((unsigned char)number);
	else
		return ((unsigned int)number);
}

int					uns_result(int length, t_base *arg_base)
{
	int		result;

	result = length;
	if (arg_base->precision > length)
		result = arg_base->precision;
	if (arg_base->wight > result)
		result = arg_base->wight;
	return (result);
}

void				unsigned_hyp(t_base *arg_base, int length,
					unsigned long int number)
{
	char	chr;

	chr = ' ';
	if (arg_base->flag_zero)
		chr = '0';
	ft_putnchr(chr, arg_base->wight - ((arg_base->precision > length)
	? (unsigned int)arg_base->precision : length));
	ft_putnchr('0', arg_base->precision - length);
	(!unsigned_null(arg_base) && number == 0) ? 1 : ft_putunbr(number);
}

int					unsigned_null(t_base *arg_base)
{
	if ((arg_base->wight <= 0 && arg_base->precision == -1) || arg_base->p_mod
		|| (arg_base->wight > 0 && arg_base->precision == -1))
		return (0);
	return (1);
}

int					unsigned_type(char **format, t_base *arg_base,
					va_list *arg_list)
{
	char				chr;
	unsigned long int	number;
	unsigned int		length;

	chr = ' ';
	number = ft_get_number(format, arg_base, arg_list);
	length = ft_numulen(number);
	if (number == 0)
		length = unsigned_null(arg_base);
	if (arg_base->precision > 0)
		arg_base->flag_zero = 0;
	if (arg_base->flag_hyphen)
	{
		ft_putnchr('0', arg_base->precision - length);
		(!unsigned_null(arg_base) && number == 0) ? 1 : ft_putnbr(number);
		ft_putnchr(chr, arg_base->wight - (arg_base->precision > (int)length
		? arg_base->precision : length));
	}
	else
		unsigned_hyp(arg_base, length, number);
	return (uns_result(length, arg_base));
}
