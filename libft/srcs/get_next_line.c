/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:23:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 17:02:14 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_append_char(char *str, char c)
{
	int		i;
	char	*str_new;

	i = 0;
	if ((str_new = (char*)malloc(sizeof(*str_new)
		* (ft_strlen(str) + 2))) == NULL)
		return (NULL);
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = c;
	str_new[i + 1] = '\0';
	free(str);
	return (str_new);
}

int				get_next_line(int fd, char **line)
{
	char	c;
	int		ret;
	char	*str;

	c = '\0';
	ret = 1;
	if ((str = (char*)malloc(sizeof(*str) * 1)) == NULL)
		return (-1);
	str[0] = '\0';
	while (c != '\n' && ret != 0)
	{
		if ((ret = read(fd, &c, 1)) == -1)
		{
			free(str);
			return (-1);
		}
		else if (c != '\n' && ret != 0)
			if ((str = ft_append_char(str, c)) == NULL)
				return (-1);
	}
	*line = str;
	if (ret == 0)
		return (0);
	else
		return (1);
}
