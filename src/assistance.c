/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:08:50 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/15 14:08:52 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	fill_initial_room(t_room *room)
{
	room->x = -1;
	room->y = -1;
	room->num = -1;
	room->name = " ";
	room->next = NULL;
}

void	zeroing_base(t_data *base)
{
	base->ants = 0;
	base->rooms = 0;
	base->adjacency = NULL;
}

void	сheck_coor(t_room *new, char **names)
{
	new->x = ft_atoi(names[1]);
	new->y = ft_atoi(names[2]);
	free(names[1]);
	free(names[2]);
	free(names[3]);
	free(names);
	if (new->x < 0 || new->x > 2147483647 || new->y < 0
		|| new->y > 2147483647)
		error("description of room is invalid");
}

t_room	*get_room(t_room *room, int num)
{
	while (room->num != num)
		room = room->next;
	return (room);
}

int		ft_length(t_ways *ways)
{
	int		i;

	i = 0;
	while (ways->next)
	{
		ways = ways->next;
		i++;
	}
	return (i);
}
