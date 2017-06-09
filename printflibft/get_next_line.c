/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:22:11 by oposhiva          #+#    #+#             */
/*   Updated: 2017/01/31 17:22:12 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_write(char *str, char **line)
{
	int		n;
	char	**l;

	n = 0;
	l = line;
	if (*str == '\0')
		return (0);
	while (str[n] != '\n' && str[n] != '\0')
		n++;
	*line = ft_strnew((sizeof(char) * n + 1));
	*line = ft_strncpy(*line, str, n);
	return (n);
}

char	*free_n_join(char *str, char *buff, int i)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	tmp[(int)ft_strlen(tmp)] = '\0';
	if (i == 1)
		free(str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int			l;
	int			i;
	char		buff[BUFF_SIZE + 1];
	static char	*str = "";

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	ft_bzero(buff, BUFF_SIZE);
	i = 0;
	while ((l = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (l == -1)
			return (-1);
		buff[l] = '\0';
		str = free_n_join(str, buff, i);
		ft_bzero(buff, BUFF_SIZE);
		i = 1;
	}
	if (!*str)
		return (0);
	str += ft_write(str, line);
	if (*str)
		str++;
	return (1);
}
