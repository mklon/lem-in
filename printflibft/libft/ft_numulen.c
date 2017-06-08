/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numulen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:33:30 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/29 15:33:31 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_numulen(unsigned long long int num)
{
	unsigned int	i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}
