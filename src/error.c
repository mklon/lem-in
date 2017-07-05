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

void	error(char *str)
{
	ft_printf("ERROR: %s\n", str);
	exit(2);
}

int		rooms_check(char *line)
{
	char	*point;

	point = line;
	if (*line == ' ' || *line == 'L' || *line == '#')
		error("description of room is invalid");
	while (*point != ' ')
	{
		if (!ft_isprint(*point) || *point == '\0')
			error("description of room is invalid");
		point++;
	}
	if (*point == ' ' && !ft_isdigit(*(++point)))
		error("description of room is invalid");
	while (*point != ' ')
	{
		if (!ft_isdigit(*point) || *point == '\0')
			error("description of room is invalid");
		point++;
	}
	if (*point == ' ' && !ft_isdigit(*(++point)))
		error("description of room is invalid");
	while (*point)
		if (!ft_isdigit(*point++))
			error("description of room is invalid");
	return (1);
}

void	links_check(char *line)
{
	char	*point;

	point = line;
	if (*line == ' ' || *line == 'L' || *line == '#')
		error("description of link is invalid");
	while (*point != '-')
	{
		if (!ft_isprint(*point) || *point == '\0' || *point == ' ')
			error("description of link is invalid");
		point++;
	}
	if (*point == '-' && (*(++point) == ' ' || !ft_isprint(*point)))
		error("description of link is invalid");
	while (*point)
	{
		if (!ft_isprint(*point) || *point == ' ')
			error("description of link is invalid");
		point++;
	}
}

void	check_for_availability(t_room *room, t_data *base, int f)
{
	if (f)
		error("file empty");
	if (!base->rooms)
		error("no rooms");
	if (base->adjacency == NULL)
		error("no links");
	if (f)
		room->name = " ";
}

int		free_line(char *line)
{
	free(line);
	return (1);
}
