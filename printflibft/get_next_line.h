/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:22:20 by oposhiva          #+#    #+#             */
/*   Updated: 2017/01/31 17:22:21 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5

# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
char	*free_n_join(char *str, char *buff, int i);
int		ft_write(char *str, char **line);

#endif
