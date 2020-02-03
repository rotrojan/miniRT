/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/27 06:27:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
int		check_is_not_directory(char *name_file)
{
	int		fd;

	errno = 0;
	if ((fd = open(name_file, O_RDONLY)))
	{
		close(fd);
	}
	return (0);
}

int		check_args_errors(int ac, char **av)
{
	if (ac < 2)
		ft_putendl_fd("usage :\n./minirt.h scene_file.rt [--save]", STDERR_FILENO);
	if (ac > 3)
		ft_putendl_fd(
			"too many arguments\nusage :\n./minirt.h scene_file.rt [--save]", STDERR_FILENO);
	if (ac == 3)
		ft_putendl_fd("usage :\n./minirt.h scene_file.rt [--save]", STDERR_FILENO);
		if (ft_strcmp(av[2], "--save") || ft_strcmp(av[2], "-save"))
			ft_putendl_fd("wrong argument\nusage :\n./minirt.h scene_file.rt [--save]", STDERR_FILENO);
	if (ac == 2)
	{
		if (ft_strcmp(av[1] + ft_strlen(av[1] - 4), ".rt"))
			ft_putendl_fd("invalid file format\nusage :\n./minirt.h scene_file.rt [--save]", STDERR_FILENO);
		if (!(check_is_not_directory(av[1])))
			ft_putendl_fd("invalid file format\nusage :\n./minirt.h scene_file.rt [--save]", STDERR_FILENO);
	}
	return (1);
}
*/
#include <stdio.h>
int		main(int ac, char **av)
{
	t_application	app;

	(void)ac;
	(void)av;
//	if (!(check_args_errors(ac, av)))
//		return (0);
	init_app(&app);
	apply_background(&app, 0x00000000);
	render(&app);
	ray_tracer(&app);
	render(&app);
	return (run_application(&app));
}
