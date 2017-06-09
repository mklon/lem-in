/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:17:57 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/09 14:17:58 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    handle_ants(char *line, t_data *base)
{
	char        *point;
	long int    l;

	point = line;
	while (*point)
		if (!ft_isdigit(*point++))
			error();
	l = ft_atoi(line);
	if (l < 1 ||l > 2147483647)
		error();
	base->ants = (int)l;
}

void    handle_start(t_data *base)
{
	char    *line;

	get_next_line(0, &line);
	if (ft_isprint())
		error();

}