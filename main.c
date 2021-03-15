/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/15 13:15:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Check errors.h and utils.c for error management.
*/

/*
** Check the third argument, and if it is ok allocate the pixel array buffer
** and launch the raytracing. The screen_shot function handle the .bmp file
** creation.
*/

static t_error	check_and_launch_screenshot(t_main *main)
{
	t_error error;

	if (!(main->mlx.data = (int*)malloc(sizeof(main->mlx.data)
		* main->mlx.win_width * main->mlx.win_height)))
		return (return_error(MALLOC_ERR));
	ray_tracer(main);
	if ((error = screen_shot(main)) != NO_ERROR)
		return (error);
	free(main->mlx.data);
	return (NO_ERROR);
}

/*
** First of all, the program initialize the main structure and set the ambient
** to -1 (in order to check later on if it has been specified in the .rt file).
** The parser is then launched. If everything goes well, the number of given
** arguments is checked. If it is three, the check_and_launch_screenshot
** function is called, otherwise the MinilibX is initialized before the
** raytracer function and MLX loop (in the run_mlx fucntion) are called.
*/

int				main(int ac, char **av)
{
	t_main		main;
	t_error		error;

	ft_bzero(&main, sizeof(main));
	main.scene.ambient.ratio = -1.0;
	if ((error = open_and_parse_file(ac, av, &main)) != NO_ERROR)
		return (return_error(error));
	if (ac == 3)
	{
		if ((error = check_and_launch_screenshot(&main)) != NO_ERROR)
			return_error(error);
	}
	else
	{
		init_mlx(&main.mlx);
		main.mlx.data = (int*)mlx_get_data_addr(main.mlx.img_ptr,
			&main.mlx.size_line, &main.mlx.bits_per_pixel, &main.mlx.endian);
		ray_tracer(&main);
		run_window(&main);
		if (!run_mlx(&main))
			return (return_error(MLX_HOOKS_ERR));
	}
	free_scene(&main.scene);
	return (EXIT_SUCCESS);
}
