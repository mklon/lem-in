/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:58:20 by oposhiva          #+#    #+#             */
/*   Updated: 2016/12/03 18:58:22 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_n_dec(long int n)
{
	int			num;

	num = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		num = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

int			long_min(long long int nn)
{
	int		len;

	len = ft_n_dec(nn);
	if (nn == LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return (-1);
	}
	return (len);
}

void		ft_putnbr(long long int n)
{
	int			len;
	long int	i;
	long int	j;
	long int	nn;

	nn = n;
	if ((len = long_min(nn)) == -1)
		return ;
	if (nn < 0)
	{
		ft_putchar('-');
		nn *= -1;
		len--;
	}
	j = 1;
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
