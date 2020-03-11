/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/11 02:11:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		key_hook(int key, t_main *main)
{
	if (key == ESC_KEY)
		close_mlx(&main->mlx);
//	if (key == S_KEY)
	return (0);
}

int				set_mlx_hooks(t_main *main)
{
	if (!(mlx_hook(main->mlx.win_ptr, KEYPRESS, NOEVENTMASK, &key_hook, main)))
		return (1);
	if (!(mlx_hook(main->mlx.win_ptr, DESTROYNOTIFY, NOEVENTMASK, &close_mlx,
		main)))
		return (1);
	if (!(mlx_loop_hook(main->mlx.win_ptr, NULL, NULL)))
		return (1);
	return (0);
}
