/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/19 03:46:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_env(t_environment *env)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_X, WIN_Y, TITLE);
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_X, WIN_Y);
	env->data = mlx_get_data_addr(env->img_ptr, &env->size_line,
		&env->bits_per_pixel, &env->endian);
}

int		run_environment(t_environment *env)
{
	mlx_loop(env);
	return (0);
}

void	apply_background(t_environment *env, t_color background)
{
	int		nb_pixels;
	int		index_pixel;
	int		index_first_byte_pixel;

	nb_pixels = WIN_X * WIN_Y;
	index_pixel = 0;
	while (index_pixel < nb_pixels)
	{
		index_first_byte_pixel = index_pixel * sizeof(int);
		env->data[index_first_byte_pixel + RED_BYTE] = background.r;
		env->data[index_first_byte_pixel + GREEN_BYTE] = background.g;
		env->data[index_first_byte_pixel + BLUE_BYTE] = background.b;
		index_pixel++;
	}
}

void	render(t_environment *env)
{
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	put_pixel(t_environment *env, t_point pixel_coord, t_color pixel_color)
{
	int		index_pixel;
	int		index_first_byte_pixel;

	if ((pixel_coord.x >= WIN_X && pixel_coord.x < 0)
		|| (pixel_coord.y >= WIN_Y && pixel_coord.y < 0))
		return ;
	index_pixel = pixel_coord.x + (pixel_coord.y * WIN_X);
	index_first_byte_pixel = index_pixel * 4;
	env->data[index_first_byte_pixel + RED_BYTE] = pixel_color.r;
	env->data[index_first_byte_pixel + GREEN_BYTE] = pixel_color.g;
	env->data[index_first_byte_pixel + BLUE_BYTE] = pixel_color.b;
}
