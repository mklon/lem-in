/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:17:57 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/09 14:17:58 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		handle_ants(char *line, t_data *base)
{
	char		*point;
	long int	l;

	point = line;
	if (!*point)
		error("the value of ants is invalid");
	while (*point)
		if (!ft_isdigit(*point++))
			error("the value of ants is invalid");
	l = ft_atoi(line);
	if (l < 1 || l > 2147483647)
		error("the value of ants is invalid");
	base->ants = (int)l;
	return (1);
}

void	allocate_2d(t_data *base)
{
	int		i;
	int		j;
	char	**array;

	i = -1;
	j = -1;
	array = (char**)malloc(sizeof(char*) * base->rooms);
	while (++i < base->rooms)
		array[i] = (char*)malloc(sizeof(char) * base->rooms + 1);
	i = -1;
	while (++i < base->rooms)
	{
		while (++j < base->rooms)
			array[i][j] = '0';
		array[i][j] = '\0';
		j = -1;
	}
	base->adjacency = array;
}

void	ft_print_array(t_data *base)
{
	int i;
	int	j;

	i = -1;
	j = -1;
	while (++i < base->rooms)
	{
		while (++j < base->rooms)
			ft_printf("%c ", base->adjacency[i][j]);
		ft_printf("\n");
		j = -1;
	}
}

void	ft_print_ways(t_ways **way, t_room *room, int len)
{
	int		i;
	t_ways	**d;

	i = -1;
	d = way;
	while (++i < len)
	{
		if (!d[i]->next)
			continue ;
		while (d[i] != NULL)
		{
			ft_printf("%s", get_room(room, d[i]->num)->name);
			d[i] = d[i]->next;
			if (d[i])
				ft_printf(" -> ");
		}
		ft_printf("\n");
	}
}

void	print_move(int num, t_ways *way, t_room *room)
{
	if (way->num == 0)
		ft_printf("\x1b[31mL%d-%s ", num, get_room(room, way->next->num)->name);
	else if (way->next->num == 1)
		ft_printf("\x1b[32mL%d-%s ", num, get_room(room, way->next->num)->name);
	else
		ft_printf("\x1b[33mL%d-%s ", num, get_room(room, way->next->num)->name);
}
