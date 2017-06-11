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

#include "../lem_in.h"

void	error(void)
{
	ft_printf("ERROR");
	exit(2);
}

void	zeroing_base(t_data *base)
{
	base->ants = 0;
	base->rooms = 0;
	base->adjacency = NULL;
}

void	rooms_check(char *line)
{
	char	*point;

	point = line;
	if (*line == ' ' || *line == 'L' || *line == '#')
		error();
	while (*point != ' ')
	{
		if (!ft_isprint(*point) || *point == '\0')
			error();
		point++;
	}
	if (*point == ' ' && !ft_isdigit(*(++point)))
		error();
	while (*point != ' ')
	{
		if (!ft_isdigit(*point) || *point == '\0')
			error();
		point++;
	}
	if (*point == ' ' && !ft_isdigit(*(++point)))
		error();
	while (*point)
		if (!ft_isdigit(*point++))
			error();
}

void	links_check(char *line)
{
	char	*point;

	point = line;
	if (*line == ' ' || *line == 'L' || *line == '#')
		error();
	while (*point == '-')
	{
		if (!ft_isprint(*point) || *point == '\0' || *point == ' ')
			error();
		point++;
	}
	if (*point == '-' && (*(++point) == ' ' || !ft_isprint(*point)))
		error();
	while (*point)
	{
		if (!ft_isprint(*point) || *point == ' ')
			error();
		point++;
	}
}
