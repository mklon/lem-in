/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:49:50 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/08 12:49:50 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	start_n_end(t_room *room)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (room)
	{
		if (room->num == 0)
			start = 1;
		if (room->num == 1)
			end = 1;
		room = room->next;
	}
	if (!start)
		error("no initial room");
	if (!end)
		error("no final room");
}

int		room_formation(t_data **base, t_room **room, char *line)
{
	static int	i = 2;

	rooms_check(line);
	create_room(*room, line, i++, *base);
	return (1);
}

int		rooms_n_links(t_data **base, t_room **room, char *line)
{
	if (ft_strchr(line, ' '))
		return (room_formation(base, room, line));
	else
	{
		allocate_2d(*base);
		start_n_end(*room);
		while (1)
		{
			ft_printf("%s\n", line);
			if (line[0] == '#')
				;
			else if (!line[0])
				error("empty line");
			else
				create_link(*room, line, *base, (*room)->next);
			free(line);
			if (!get_next_line(0, &line))
				break ;
		}
	}
	return (0);
}

void	ft_read_lines(t_data **base, t_room **room, int f, int i)
{
	char		*l;

	while (get_next_line(0, &l) > 0)
	{
		if (!l[0])
			error("empty line");
		else if (ft_strequ("##start", l) && ft_printf("##start\n")
				&& free_line(l) && get_next_line(0, &l) > 0 && rooms_check(l))
			create_room(*room, l, 0, *base);
		else if (ft_strequ("##end", l) && ft_printf("##end\n")
				&& free_line(l) && get_next_line(0, &l) > 0 && rooms_check(l))
			create_room(*room, l, 1, *base);
		else if (l[0] == '#')
			;
		else if (f && handle_ants(l, *base))
			f = 0;
		else
			i = rooms_n_links(base, room, l);
		if (i)
		{
			ft_printf("%s\n", l);
			free(l);
		}
	}
	check_for_availability(*room, *base, f);
}
