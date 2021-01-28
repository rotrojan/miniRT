/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/27 16:50:19 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
		mlx->win_height, TITLE);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
	mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->size_line,
		&mlx->bits_per_pixel, &mlx->endian);
}

t_bool	run_mlx(t_main *main)
{
	if (!(set_mlx_hooks(main)))
		return (FALSE);
	mlx_loop(main->mlx.mlx_ptr);
	return (TRUE);
}

int		close_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	apply_background(t_mlx *mlx, int color)
{
	int		nb_pixels;
	int		index_pixel;

	index_pixel = 0;
	nb_pixels = mlx->win_width * mlx->win_height;
	while (index_pixel < nb_pixels)
		mlx->data[index_pixel++] = color;
}

void	put_pixel(t_mlx *mlx, int x, int y, t_color color)
{
	int		(*pixel_array)[mlx->win_width][1];
	int		final_color;

	if ((x >= mlx->win_width && x < 0) || (y >= mlx->win_height && y < 0))
		return ;
	final_color = ((((int)(color.r * 255) << 8)
		| (int)(color.g * 255)) << 8) | (int)(color.b * 255);
	pixel_array = (void*)mlx->data;
	*pixel_array[y][x] = final_color;
}
