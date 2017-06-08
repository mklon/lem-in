/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:25:55 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 15:25:56 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				binary_type(t_base *arg_base, va_list *arg_list)
{
	unsigned int		lenght;
	unsigned long int	number;

	number = va_arg(*arg_list, unsigned long int);
	if (arg_base->flag_hyphen)
	{
		lenght = display_notation(number, 2, &lenght, 1);
		ft_putnchr(' ', arg_base->wight - lenght);
	}
	else
	{
		lenght = display_notation(number, 2, &lenght, 0);
		ft_putnchr(arg_base->flag_zero ? '0' : ' ', arg_base->wight - lenght);
		display_notation(number, 2, &lenght, 1);
	}
	return ((arg_base->wight > (int)lenght) ? arg_base->wight : lenght);
}

unsigned int	display_notation(unsigned long int num, int base,
				unsigned int *len, int f)
{
	char	*temp;

	temp = "0123456789abcdef";
	if (num >= (unsigned long int)base)
		display_notation(num / base, base, len, f);
	if (f)
		ft_putchar(temp[num % base]);
	(*len)++;
	return (*len);
}
