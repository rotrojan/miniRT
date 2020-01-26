/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/25 23:04:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_app(t_application *app)
{
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_X, WIN_Y, TITLE);
	app->img_ptr = mlx_new_image(app->mlx_ptr, WIN_X, WIN_Y);
	app->data = (int*)mlx_get_data_addr(app->img_ptr, &app->size_line,
		&app->bits_per_pixel, &app->endian);
}

int		run_application(t_application *app)
{
	set_mlx_hooks(app);
	if (!(set_mlx_hooks(app)))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (-1);
	}
	mlx_loop(app->mlx_ptr);
	return (0);
}

int		close_application(t_application *app)
{
	mlx_destroy_font(app->mlx_ptr);
	mlx_destroy_image(app->mlx_ptr, app->img_ptr);
	mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	exit(0);
	return (-1);
}

void	render(t_application *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
}

void	put_pixel(t_application *app, int x, int y, int color)
{
	int		(*pixel_array)[WIN_X][1];

	if ((x >= WIN_X && x < 0) || (y >= WIN_Y && y < 0))
		return ;
	pixel_array = (void*)app->data;
	*pixel_array[y][x] = color;
}
