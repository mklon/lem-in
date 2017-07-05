/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:01:30 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/16 14:01:31 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_ways	**array_allocate(t_room *room, int num)
{
	int		i;
	t_ways	**ways;

	i = 0;
	while (room->num != 0)
		room = room->next;
	ways = (t_ways**)malloc(sizeof(t_ways) * num + 1);
	while (i < num)
	{
		ways[i] = malloc(sizeof(t_ways));
		ways[i]->next = NULL;
		ways[i]->num = room->num;
		i++;
	}
	ways[i] = NULL;
	return (ways);
}

void	one_way(t_data *base, t_room *room)
{
	int		i;
	t_room	*end;

	i = 0;
	end = get_room(room, 1);
	while (++i <= base->ants)
		ft_printf("\x1b[32mL%d-%s ", i, end->name);
	ft_printf("\n");
	exit(0);
}

t_ways	**get_ways(t_data *base, t_room *room, int num)
{
	int		i;
	int		j;
	t_core	*core;
	t_ways	**ways;

	i = 0;
	j = 2;
	core = malloc(sizeof(t_core));
	core->base = base;
	core->room = room;
	if (base->adjacency[0][1] == '1')
		one_way(base, room);
	ways = array_allocate(room, num);
	while (j < base->rooms && i < num)
	{
		core->way = ways[i];
		if (recursion(core, j, 0, 0))
			i++;
		else
			j++;
	}
	if (!ways[0]->next)
		error("there is no way");
	free(core);
	return (ways);
}
