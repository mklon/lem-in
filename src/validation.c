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

void	check_for_rest(t_room *room, char *line)
{
	if (ft_strchr(line, ' '))
		create_room(room, line, 8);
	creat_link(line);
}

void	ft_read_lines(t_data *base, t_room *rooms)
{
	char	*line;

	get_next_line(0, &line);
	handle_ants(line, base);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ("##start", line))
			handle_start(base, rooms);
		/*else if (ft_strequ("##end", line))
			handle_end();
		else if (line[0] == '#' && line[1] == '#')
			handle_comments();
		else if (line[0] == '#')
			handle_commands();*/
		else
			check_for_rest(rooms, line);
	}
}
