/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:03:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/15 14:25:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** All these functions are self explanatories. Check out the MLX "documentation"
** for further informations ... try not to cry.
*/

t_bool	run_mlx(t_main *main)
{
	if (!(set_mlx_hooks(main)))
		return (FALSE);
	mlx_loop(main->mlx.mlx_ptr);
	return (TRUE);
}

int		run_window(t_main *main)
{
	mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr,
		main->mlx.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int		close_mlx(t_main *main)
{
	mlx_loop_end(main->mlx.mlx_ptr);
	mlx_destroy_image(main->mlx.mlx_ptr, main->mlx.img_ptr);
	mlx_destroy_window(main->mlx.mlx_ptr, main->mlx.win_ptr);
	mlx_destroy_display(main->mlx.mlx_ptr);
	free(main->mlx.mlx_ptr);
	free_scene(&main->scene);
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->screen_width, &mlx->screen_height);
	mlx->win_width = fmin(mlx->win_width, mlx->screen_width);
	mlx->win_height = fmin(mlx->win_height, mlx->screen_height);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
		mlx->win_height, TITLE);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
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
