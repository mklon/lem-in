/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:43:37 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 15:43:37 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

intmax_t	size_def(char **format, t_base *arg_base, va_list *arg_list)
{
	intmax_t	number;

	number = va_arg(*arg_list, intmax_t);
	if (**format == 'D' || arg_base->ll == 1)
		return ((long long int)number);
	else if (arg_base->j == 1)
		return (number);
	else if (arg_base->l == 1)
		return ((long int)number);
	else if (arg_base->z == 1)
		return ((size_t)number);
	else if (arg_base->hh == 1)
		return ((char)number);
	else if (arg_base->h == 1)
		return ((short int)number);
	else
		return ((int)number);
}

int			prefix(t_base *arg_base, long long int *num, int f)
{
	if (arg_base->flag_plus || *num < 0)
	{
		if (f)
		{
			if (*num >= 0)
				write(1, "+", 1);
			else
			{
				write(1, "-", 1);
				*num *= -1;
				arg_base->flag_plus = 1;
			}
		}
		arg_base->wight--;
		return (1);
	}
	if (arg_base->flag_space)
	{
		if (f)
			write(1, " ", 1);
		arg_base->wight--;
		return (1);
	}
	return (0);
}

int			result(t_base *arg_base, int num_len, int i)
{
	int		tmp;
	int		minus;

	minus = (arg_base->flag_hyphen ? 2 : 3);
	tmp = arg_base->precision + i;
	if (arg_base->wight + minus * i > arg_base->precision)
		tmp = arg_base->wight + minus * i;
	if (tmp > num_len)
		return (tmp);
	return (num_len + i);
}

void		integer_hup(t_base *arg_base, int num_len, long long int num)
{
	char	chr;

	chr = (arg_base->flag_zero && !arg_base->precision ? '0' : ' ');
	prefix(arg_base, &num, (arg_base->flag_zero) ? 1 : 0);
	ft_putnchr(chr, arg_base->wight - ((arg_base->precision >= num_len)
	? arg_base->precision : num_len));
	prefix(arg_base, &num, (arg_base->flag_zero) ? 0 : 1);
	ft_putnchr('0', arg_base->precision - num_len);
	(!unsigned_null(arg_base) && num == 0) ? 1 : ft_putnbr(num);
}

int			integer_type(char **format, t_base *arg_base, va_list *arg_list)
{
	int					num_len;
	long long int		num;

	if (arg_base->precision)
		arg_base->flag_zero = 0;
	num = (long long int)size_def(format, arg_base, arg_list);
	num_len = ft_numlen(num);
	if (num == 0)
		num_len = unsigned_null(arg_base);
	if (arg_base->flag_hyphen)
	{
		prefix(arg_base, &num, 1);
		ft_putnchr('0', arg_base->precision - num_len);
		(!unsigned_null(arg_base) && num == 0) ? 1 : ft_putnbr(num);
		ft_putnchr(' ', arg_base->wight - ((arg_base->precision >= num_len) ?
		arg_base->precision : num_len));
	}
	else
		integer_hup(arg_base, num_len, num);
	return (result(arg_base, num_len, prefix(arg_base, &num, 0)));
}
