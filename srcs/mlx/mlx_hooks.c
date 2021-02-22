/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/22 08:28:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* void	rotate_cam(int key, t_main *main) */
/* { */
	/* ft_bzero(main->mlx.data, main->mlx.win_width * main->mlx.win_height * 4); */
	/* if (key == UP_KEY) */
		/* ((t_object*)main->scene.cam_lst->content)->obj_prop.camera.orientation.y */
			/* += 0.1; */
	/* if (key == DOWN_KEY) */
		/* ((t_object*)main->scene.cam_lst->content)->obj_prop.camera.orientation.y */
			/* -= 0.1; */
	/* if (key == LEFT_KEY) */
		/* ((t_object*)main->scene.cam_lst->content)->obj_prop.camera.orientation.x */
			/* -= 0.1; */
	/* if (key == RIGHT_KEY) */
		/* ((t_object*)main->scene.cam_lst->content)->obj_prop.camera.orientation.x */
			/* += 0.1; */
	/* ray_tracer(main); */
	/* mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr, */
		/* main->mlx.img_ptr, 0, 0); */
/* } */

void	move_cam(int key, t_main *main)
{
	ft_bzero(main->mlx.data, main->mlx.win_width * main->mlx.win_height * 4);
	if (key == W_KEY)
		((t_object*)main->scene.cam_lst->content)->position.z -= 1;
	if (key == S_KEY)
		((t_object*)main->scene.cam_lst->content)->position.z += 1;
	if (key == Q_KEY)
		((t_object*)main->scene.cam_lst->content)->position.y += 1;
	if (key == E_KEY)
		((t_object*)main->scene.cam_lst->content)->position.y -= 1;
	if (key == A_KEY)
		((t_object*)main->scene.cam_lst->content)->position.x -= 1;
	if (key == D_KEY)
		((t_object*)main->scene.cam_lst->content)->position.x += 1;
	ray_tracer(main);
	mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr,
		main->mlx.img_ptr, 0, 0);
}

void	switch_cam(t_main *main)
{
	ft_bzero(main->mlx.data, main->mlx.win_width * main->mlx.win_height * 4);
	main->scene.cam_lst = main->scene.cam_lst->next;
	ray_tracer(main);
	mlx_put_image_to_window(main->mlx.mlx_ptr, main->mlx.win_ptr,
		main->mlx.img_ptr, 0, 0);
}

static int		key_hook(int key, t_main *main)
{
	if (key == ESC_KEY)
		close_mlx(&main->mlx);
	/* if (key == UP_KEY || key == DOWN_KEY || key == RIGHT_KEY || key == LEFT_KEY) */
		/* rotate_cam(key, main); */
	if (key == Q_KEY || key == W_KEY || key == E_KEY || key == A_KEY
			|| key == S_KEY || key == D_KEY)
		move_cam(key, main);
	if (key == SP_KEY)
		switch_cam(main);
	if (!run_mlx(main))
		return (return_error(MLX_HOOKS_ERR));
	return (0);
}

int				set_mlx_hooks(t_main *main)
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
