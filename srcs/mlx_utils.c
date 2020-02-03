/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/02 20:10:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_app(t_application *app)
{
	app->win_width = 900;
	app->win_height = 1200;
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, app->win_width,
		app->win_height, TITLE);
	app->img_ptr = mlx_new_image(app->mlx_ptr, app->win_width, app->win_height);
	app->data = (int*)mlx_get_data_addr(app->img_ptr, &app->size_line,
		&app->bits_per_pixel, &app->endian);
}

int		run_application(t_application *app)
{
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

void	put_pixel(t_application *app, int x, int y, t_color color)
{
	int		(*pixel_array)[app->win_width][1];
	int		final_color;

	if ((x >= app->win_width && x < 0) || (y >= app->win_height && y < 0))
		return ;
	final_color = ((((int)(color[0] * 255) << 8)
		+ (int)(color[1] * 255)) << 8) + (int)(color[2] * 255);
	pixel_array = (void*)app->data;
	*pixel_array[y][x] = final_color;
}
