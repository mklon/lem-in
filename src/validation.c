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

void	check_for_rest(t_room **room, char *line)
{
	static int	i = 2;

	if (ft_strchr(line, ' '))
		create_room(room, line, i++);
	else
		;//create_link(line);
}

void	ft_read_lines(t_data *base, t_room *room)
{
	char	*line;
	t_room	*temp;

	get_next_line(0, &line);
	handle_ants(line, base);
	temp = room;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strequ("##start", line) && get_next_line(0, &line) > 0)
			create_room(&temp, line, 0);
		else if (ft_strequ("##end", line) && get_next_line(0, &line) > 0)
			create_room(&temp, line, 1);
		/*else if (line[0] == '#' && line[1] == '#')
			handle_comments();
		else if (line[0] == '#')
			handle_commands();*/
		else
			check_for_rest(&temp, line);
	}
}
