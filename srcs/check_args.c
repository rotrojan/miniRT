/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 02:16:40 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/07 02:59:14 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		check_args(int ac, char **av)
{
	int		fd;
	char	tmp[1];

	if (ac < 2 || ac > 3)
	{
		perror(NULL);
		return (FALSE);
	}
	if (ft_strcmp(".rt", av[1] + ft_strlen(av[1]) - 3))
	{
		perror(NULL);
		return (FALSE);
	}
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if (read(fd, tmp, 1) == -1)
		{
			perror(NULL);
			close(fd);
			return (FALSE);
		}
		close(fd);
	}
	return (TRUE);
}

t_bool		parser(char *rt_file)
{
	int		fd;
	

	if ((fd = open(rt_file, O_RDONLY)) != -1)
	{

		close(fd);
	}
	perror(NULL);
	return (FALSE);
}
