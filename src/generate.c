/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:19:54 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/11 14:19:54 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	create_room(t_room **room, char *line, int number)
{
	char    *point;

	rooms_check(line);
	*room = malloc(sizeof(t_room)); //malloc
	(*room)->num = (unsigned int)number;
	point = line;
	while (*point != ' ')
		point++;
	(*room)->name = malloc(sizeof(char) * (point - line) + 1); //malloc
	ft_strncpy((*room)->name, line, point - line);
	*room = (*room)->next;
}