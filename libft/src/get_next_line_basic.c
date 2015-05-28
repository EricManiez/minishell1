/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaniez <emaniez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:52:21 by emaniez           #+#    #+#             */
/*   Updated: 2015/03/17 15:05:44 by emaniez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		get_line_leftovers(char **line, char **buf)
{
	int	i;

	i = -1;
	while ((*buf)[++i] && (*buf)[i] != '\n')
		*line = ft_charjoin_f(line, (*buf)[i]);
	*buf = ft_strchr(*buf, '\n');
	if (*buf && **buf == '\n')
	{
		(*buf)++;
		return (1);
	}
	return (0);
}

int		get_next_line_basic(int const fd, char **line)
{
	static char	*buf;
	int			rd;

	if (**line)
		ft_strdel(line);
	*line = ft_memalloc(1);
	if (buf && *buf)
	{
		if (get_line_leftovers(line, &buf))
			return (1);
	}
	buf = ft_memalloc(BUF_SIZE + 1);
	while ((rd = read(fd, buf, BUF_SIZE)) && !ft_strchr(buf, '\n'))
	{
		buf[rd] = '\0';
		*line = ft_strjoin_fl(line, buf);
		ft_bzero(buf, BUF_SIZE + 1);
	}
	if (rd < 1)
		return (rd);
	get_line_leftovers(line, &buf);
	return (1);
}
