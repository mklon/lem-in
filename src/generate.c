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

void	create_room(t_room *room, char *line, int number, t_data *base)
{
	t_room	*new;
	t_room	*temp;
	char	**names;

	names = ft_strsplit(line, ' ');
	new = malloc(sizeof(t_room));
	сheck_coor(new, names);
	while (room != NULL)
	{
		if (number == room->num)
			error("too many initial or final rooms");
		if (!ft_strcmp(names[0], room->name))
			error("the same name more than once");
		if (new->x == room->x && new->y == room->y)
			error("the same coordinates more than once");
		temp = room;
		room = (room)->next;
	}
	new->num = number;
	new->name = names[0];
	new->next = NULL;
	new->ant = 0;
	new->mark = 0;
	temp->next = new;
	base->rooms++;
}

void	create_link(t_room *room, char *line, t_data *base, t_room *first)
{
	t_room	*second;

	links_check(line);
	while (first)
	{
		if (ft_strncmp(line, first->name, ft_strlen(first->name)) == 0)
			if (*(line + ft_strlen(first->name)) == '-')
			{
				second = room->next;
				while (second)
				{
					if (ft_strcmp(line + ft_strlen(first->name) + 1,
						second->name) == 0)
					{
						base->adjacency[first->num][second->num] = '1';
						base->adjacency[second->num][first->num] = '1';
						return ;
					}
					second = second->next;
				}
			}
		first = first->next;
	}
	error("link with non existing room");
}
