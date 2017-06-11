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

typedef struct  s_base
{
	int			ants;
	int			rooms;
	char		**adjacency;
}				t_data;

typedef struct  s_room
{
	char        *name;

}               t_room;
/*
** main.c
*/
int				main(void);

/*
** validation.c
*/
void			ft_read_lines(t_data *base, t_room *rooms);

/*
* error.c
*/
void			error(void);
void			zeroing_base(t_data *base);
void			rooms_check(char *line);

/*
* handle.c
*/
void			handle_ants(char *line, t_data *base);
void			handle_start(t_data *base, t_room *rooms);

#endif