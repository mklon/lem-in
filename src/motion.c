/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:56:28 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/17 16:56:30 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		del_last_room(t_ways *ways)
{
	if (!ways || !ways->next)
		return (0);
	while (ways->next->next != NULL)
		ways = ways->next;
	free(ways->next);
	ways->next = NULL;
	return (0);
}

int		get_directions(t_ways *way, int j)
{
	t_ways *new;

	while (way->next != NULL)
		way = way->next;
	new = malloc(sizeof(t_ways));
	new->num = j;
	new->next = NULL;
	way->next = new;
	return (1);
}

int		recursion(t_core *core, int len, int i, int n)
{
	int		j;
	t_room	*place;

	j = 0;
	place = get_room(core->room, i);
	if (i == 1)
		return (1);
	place->mark = 1;
	if (n > len)
	{
		place->mark = del_last_room(core->way);
		return (0);
	}
	while (++j < core->base->rooms)
		if (!(get_room(core->room, j)->mark)
			&& i != j && core->base->adjacency[i][j] == '1')
		{
			if (get_directions(core->way, j)
				&& recursion(core, len, j, n + 1))
				return (1);
			else
				place->mark = 0;
		}
	del_last_room(core->way);
	return (0);
}
