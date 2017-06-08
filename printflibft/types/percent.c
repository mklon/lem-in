/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:02:43 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 16:02:43 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		percent_sign_type(t_base *arg_base)
{
	char	chr_arg;

	chr_arg = '%';
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
