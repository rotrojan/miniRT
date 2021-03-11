/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/10 22:54:23 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	switch_cam(t_main *main)
{
	ft_bzero(main->mlx.data, main->mlx.win_width * main->mlx.win_height * 4);
	main->scene.cam_lst = main->scene.cam_lst->next;
	ray_tracer(main);
	mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr,
		main->mlx.img_ptr, 0, 0);
}

static int	key_hook(int key, t_main *main)
{
	if (key == ESC_KEY)
		close_mlx(&main->mlx);
	if (key == SP_KEY)
		switch_cam(main);
	if (!run_mlx(main))
		return (return_error(MLX_HOOKS_ERR));
	return (0);
}

int			set_mlx_hooks(t_main *main)
{
	if (!(mlx_key_hook(main->mlx.win_ptr, &key_hook, main)))
		return (1);
	if (!(mlx_hook(
		main->mlx.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &close_mlx,
		main)))
		return (1);
	if (!(mlx_loop_hook(main->mlx.win_ptr, NULL, NULL)))
		return (1);
	return (0);
}
