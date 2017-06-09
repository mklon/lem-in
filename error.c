/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:09:06 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/08 13:09:06 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    error(void)
{
	ft_printf("ERROR");
	exit(2);
}

void    zeroing_base(t_data *base)
{
	base->ants = 0;
	base->rooms = 0;
	base->adjacency = NULL;
}
