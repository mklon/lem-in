/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:19:43 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/07 14:19:44 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	usage(void)
{
	ft_printf("usage: ./lem-in [-w] < source_file");
	exit(2);
}

void	bonus(char **argv, t_room *room, t_ways **ways, int i)
{
	if (ft_strcmp(argv[1], "-w"))
		usage();
	ft_printf("\n");
	ft_print_ways(ways, room, i);
}

int		main(int argc, char **argv)
{
	int		i;
	t_data	*base;
	t_room	*room;
	t_ways	**way;
	t_core	*core;

	if (argc > 2 || ft_strcmp(argv[1], "-w"))
		usage();
	base = malloc(sizeof(t_data));
	room = malloc(sizeof(t_room));
	core = malloc(sizeof(t_core));
	zeroing_base(base);
	fill_initial_room(room);
	ft_read_lines(&base, &room, 1, 1);
	i = (base->ants < base->rooms - 2) ? base->ants : base->rooms - 2;
	way = get_ways(base, room, i);
	ft_printf("\n");
	core->base = base;
	core->room = room;
	core->ways = way;
	escape(core, -1);
	if (argc == 2)
		bonus(argv, room, way, i);
	return (0);
}
