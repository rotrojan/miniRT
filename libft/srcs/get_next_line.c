/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:23:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/22 20:10:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 256

static int		append_line(char **s_buff, char **line, int fd, ssize_t ret)
{
	char	*tmp;

	tmp = *s_buff;
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp == '\n')
	{
		if (!(*line = ft_substr(*s_buff, 0, (size_t)(tmp - *s_buff))))
			return (-1);
		if (!(tmp = ft_strdup(++tmp)))
			return (-1);
		free(*s_buff);
		*s_buff = tmp;
	}
	else if (!*tmp)
	{
		if (ret == BUFFER_SIZE)
			get_next_line(fd, line);
		if (!(*line = ft_strdup(*s_buff)))
			return (-1);
		free(*s_buff);
		*s_buff = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*s_buff = NULL;
	char			r_buff[BUFFER_SIZE + 1];
	char			*tmp;
	ssize_t			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, r_buff, BUFFER_SIZE)) > 0)
	{
		r_buff[ret] = '\0';
		tmp = ft_strjoin(s_buff, r_buff);
		free(s_buff);
		s_buff = tmp;
		if (ft_strchr(s_buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (!ret && (!s_buff || !*s_buff))
	{
		*line = ft_strdup("");
		return (0);
	}
	return (append_line(&s_buff, line, fd, ret));
}

#endif
