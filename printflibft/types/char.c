/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:28:29 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 15:28:29 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		character_type(t_base *arg_base, va_list *arg_list)
{
	char	chr_arg;

	if (arg_base->ll || arg_base->l)
		return (wcharacter_type(arg_base, arg_list));
	chr_arg = (char)va_arg(*arg_list, int);
	if (arg_base->flag_hyphen)
	{
		ft_putchar(chr_arg);
		ft_putnchr(' ', arg_base->wight - 1);
	}
	else
	{
		ft_putnchr(arg_base->flag_zero ? '0' : ' ', arg_base->wight - 1);
		ft_putchar(chr_arg);
	}
	return (arg_base->wight ? arg_base->wight : 1);
}
