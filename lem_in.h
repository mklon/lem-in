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

/*
** main.c
*/
int		main(int atgc, char **argv);

/*
** validation.c
*/
void    ft_read_lines();

/*
* error.c
*/
void    error(void);

#endif