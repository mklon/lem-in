/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:10:44 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/29 15:10:45 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_dec(unsigned long long int n)
{
	int			num;

	num = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

void		ft_putunbr(unsigned long long int n)
{
	int						len;
	long int				i;
	unsigned long long int	j;
	unsigned long long int	nn;

	nn = n;
	j = 1;
	len = ft_n_dec(nn);
	while (--len > 0)
		j *= 10;
	len = ft_n_dec(nn) + 1;
	while (--len > 0)
	{
		i = nn / j;
		nn = nn - i * j;
		j /= 10;
		ft_putchar((char)(i + '0'));
	}
}
