/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 15:35:19 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Erase the current image, switch to the next camera, raytrace again and load
** the new image.
*/

static void	switch_cam(t_main *main)
{
	ft_bzero(main->mlx.data, main->mlx.win_width * main->mlx.win_height * 4);
	main->scene.cam_lst = main->scene.cam_lst->next;
	ray_tracer(main);
	mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr,
		main->mlx.img_ptr, 0, 0);
}

/*
** Launch the function corresponding to the received event.
*/

static int	key_hook(int key, t_main *main)
{
	if (key == XK_Escape)
		close_mlx(main);
	if (key == XK_space)
		switch_cam(main);
	if (!run_mlx(main))
		return (return_error(MLX_HOOKS_ERR));
	return (0);
}

/*
** The mlx_loop_hook function wait for key or mouse events.
** For more informations about events management with the MlX, check out the MLX
** "documentation" ... and try not to cry.
*/

int			set_mlx_hooks(t_main *main)
{
	if (!(mlx_hook(
		main->mlx.win_ptr, ClientMessage, StructureNotifyMask, &close_mlx,
		main)))
		return (1);
	if (!(mlx_hook(
		main->mlx.win_ptr, VisibilityNotify, VisibilityChangeMask, &run_window,
		main)))
		return (1);
	if (!(mlx_key_hook(main->mlx.win_ptr, &key_hook, main)))
		return (1);
	if (!(mlx_loop_hook(main->mlx.win_ptr, NULL, NULL)))
		return (1);
	return (0);
}
