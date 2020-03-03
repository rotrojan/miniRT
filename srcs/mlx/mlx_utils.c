/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 01:02:28 by rotrojan         ###   ########.fr       */
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

int		run_mlx(t_mlx *mlx)
{
	if (!(set_mlx_hooks(mlx)))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (-1);
	}
	mlx_loop(mlx->mlx_ptr);
	return (EXIT_SUCCESS);
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

	nb_pixels = mlx->win_width * mlx->win_height;
	index_pixel = 0;
	while (index_pixel < nb_pixels)
		mlx->data[index_pixel++] = color;
}

void	put_pixel(t_mlx *mlx, int x, int y, t_color color)
{
	int		(*pixel_array)[mlx->win_width][1];
	int		final_color;

	if ((x >= mlx->win_width && x < 0) || (y >= mlx->win_height && y < 0))
		return ;
	final_color = ((((int)(color[0] * 255) << 8)
		+ (int)(color[1] * 255)) << 8) + (int)(color[2] * 255);
	pixel_array = (void*)mlx->data;
	*pixel_array[y][x] = final_color;
}
