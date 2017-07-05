/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:13:38 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/20 15:13:38 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	next_step(t_core *core, int j, int i)
{
	while (core->ways[++j] && core->ways[j]->next
		&& (core->base->ants - i)
		>= ft_length(core->ways[j]) - ft_length(core->ways[j]))
		step(core->base, core->room, core->ways[j]);
}

void	multiwhip(t_core *core, int *i)
{
	int		j;

	j = 0;
	while (core->ways[++j] && core->ways[j]->next
		&& (core->base->ants - *i) > 0 && (core->base->ants - *i)
		>= ft_length(core->ways[j]) - ft_length(core->ways[0]))
	{
		(*i)++;
		get_room(core->room, core->ways[j]->num)->ant = *i;
		step(core->base, core->room, core->ways[j]);
	}
	next_step(core, j, *i - 1);
}

void	step(t_data *base, t_room *room, t_ways *way)
{
	t_room	*near;

	if (!way->next)
		return ;
	step(base, room, way->next);
	near = get_room(room, way->num);
	if (near->ant)
	{
		get_room(room, way->next->num)->ant = near->ant;
		print_move(near->ant, way, room);
		near->ant = 0;
		if (way->next->num == 1)
			get_room(room, 1)->mark++;
	}
}

void	escape(t_core *core, int i)
{
	int		dop;
	int		num;

	num = 0;
	while (++num <= core->base->ants)
	{
		get_room(core->room, 0)->ant = num;
		step(core->base, core->room, core->ways[0]);
		if (core->ways[1] && core->ways[1]->next && (core->base->ants - i) > 0
			&& (core->base->ants - i) >= ft_length(core->ways[1])
			- ft_length(core->ways[0]))
			multiwhip(core, &num);
		else
			next_step(core, 0, num - 1);
		ft_printf("\n");
	}
	while (get_room(core->room, 1)->mark < core->base->ants)
	{
		dop = -1;
		while (core->ways[++dop] && core->ways[dop]->next)
			step(core->base, core->room, core->ways[dop]);
		ft_printf("\n");
	}
}
