/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:20:17 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/07 14:20:18 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include "printflibft/get_next_line.h"
# include "printflibft/ft_printf.h"
# include "printflibft/libft/libft.h"

typedef struct		s_core
{
	struct s_room	*room;
	struct s_base	*base;
	struct s_ways	*way;
	struct s_ways	**ways;
}					t_core;

typedef struct		s_base
{
	int				ants;
	int				rooms;
	char			**adjacency;
}					t_data;

typedef struct		s_ways
{
	int				num;
	struct s_ways	*next;
}					t_ways;

typedef struct		s_room
{
	char			*name;
	int				num;
	long int		x;
	long int		y;
	int				ant;
	int				mark;
	struct s_room	*next;

}					t_room;

/*
** main.c
*/
int					main(int argc, char **argv);
void				bonus(t_room *room, t_ways **ways, int i);
void				usage(void);

/*
** validation.c
*/
void				ft_read_lines(t_data **base, t_room **rooms, int f, int i);
int					rooms_n_links(t_data **base, t_room **room, char *line);
int					room_formation(t_data **base, t_room **room, char *line);
void				start_n_end(t_room *room);

/*
** error.c
*/
void				error(char *str);
int					free_line(char *line);

int					rooms_check(char *line);
void				links_check(char *line);
void				check_for_availability(t_room *room, t_data *base, int f);

/*
** handle.c
*/
int					handle_ants(char *line, t_data *base);
void				allocate_2d(t_data *base);
void				ft_print_array(t_data *base);
void				ft_print_ways(t_ways **way, t_room *room, int len);
void				print_move(int num, t_ways *way, t_room *room);

/*
** generate.c
*/
void				create_room(t_room *room, char *line, int number,
								t_data *base);
void				create_link(t_room *room, char *line,
								t_data *base, t_room *first);

/*
** assistance.c
*/
void				fill_initial_room(t_room *room);
void				zeroing_base(t_data *base);
void				сheck_coor(t_room *new, char **names);
t_room				*get_room(t_room *room, int num);
int					ft_length(t_ways *ways);

/*
** directions.c
*/
t_ways				**get_ways(t_data *base, t_room *room, int num);
void				one_way(t_data *base, t_room *room);
t_ways				**array_allocate(t_room *room, int num);

/*
** motion.c
*/
int					recursion(t_core *core, int len, int i, int n);
int					get_directions(t_ways *way, int j);
int					del_last_room(t_ways *ways);

/*
** race.c
*/
void				escape(t_core *core, int i);
void				step(t_data *base, t_room *room, t_ways *way);
void				multiwhip(t_core *core, int *i);
void				next_step(t_core *core, int j, int i);

/*
** bonus.c
*/
void				usage(void);
void				bonus_ways(char **argv, t_ways **way, t_room *room, int i);
void				bonus_num(int num, char **argv);

#endif
