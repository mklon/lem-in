/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   none.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:23:44 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/17 12:23:46 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		none_type(char **format, t_base *arg_base)
{
	if (arg_base->flag_hyphen)
	{
		ft_putchar(**format);
		ft_putnchr(' ', arg_base->wight - 1);
	}
	else
	{
		ft_putnchr(arg_base->flag_zero ? '0' : ' ', arg_base->wight - 1);
		ft_putchar(**format);
	}
	return (arg_base->wight ? arg_base->wight : 1);
}
