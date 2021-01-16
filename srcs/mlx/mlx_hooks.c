/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/16 12:10:35 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		key_hook(int key, t_main *main)
{
	/* if (key == XK_Escape) */
	if (key == ESC_KEY)
		close_mlx(&main->mlx);
	return (0);
}

int				set_mlx_hooks(t_main *main)
{
	if (!(mlx_key_hook(main->mlx.win_ptr, &key_hook, main)))
		return (1);
	/* if (!(mlx_hook(main->mlx.win_ptr, DestroyNotify, StructureNotifyMask, &close_mlx, */
	if (!(mlx_hook(main->mlx.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &close_mlx,
		main)))
		return (1);
	if (!(mlx_loop_hook(main->mlx.win_ptr, NULL, NULL)))
		return (1);
	return (0);
}
