/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/11 10:36:10 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_error	check_and_launch_screenshot(char **av, t_main *main)
{
	t_error ret;

	if (!ft_strcmp("-save", av[2]) || !ft_strcmp("--save", av[2]))
	{
		if (!(main->mlx.data = (int*)malloc(sizeof(main->mlx.data)
			* main->mlx.win_width * main->mlx.win_height)))
			return (return_error(MALLOC_ERR));
		ray_tracer(main);
		if ((ret = screen_shot(main)) != NO_ERROR)
			return (ret);
		free(main->mlx.data);
	}
	return (NO_ERROR);
}

int				main(int ac, char **av)
{
	t_main		main;
	t_error		ret;

	ft_bzero(&main, sizeof(main));
	main.scene.ambient.ratio = -1.0;
	if ((ret = open_and_parse_file(ac, av, &main)) != NO_ERROR)
		return (return_error(ret));
	if (ac == 3)
	{
		if ((ret = check_and_launch_screenshot(av, &main)) != NO_ERROR)
			return_error(ret);
	}
	else
	{
		init_mlx(&main.mlx);
		main.mlx.data = (int*)mlx_get_data_addr(main.mlx.img_ptr,
			&main.mlx.size_line, &main.mlx.bits_per_pixel, &main.mlx.endian);
		ray_tracer(&main);
		mlx_put_image_to_window(main.mlx.mlx_ptr, main.mlx.win_ptr,
			main.mlx.img_ptr, 0, 0);
		if (!run_mlx(&main))
			return (return_error(MLX_HOOKS_ERR));
	}
	free_scene(&main.scene);
	return (EXIT_SUCCESS);
}
