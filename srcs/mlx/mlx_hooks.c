/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/01 05:47:57 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		close_mlx(mlx);
	return (0);
}

int				set_mlx_hooks(t_mlx *mlx)
{
	if (!(mlx_hook(mlx->win_ptr, KEYPRESS, NOEVENTMASK, &key_hook, mlx)))
		return (1);
	if (!(mlx_hook(mlx->win_ptr, DESTROYNOTIFY, NOEVENTMASK, &close_mlx, mlx)))
		return (1);
	if (!(mlx_loop_hook(mlx->mlx_ptr, NULL, NULL)))
		return (1);
	return (0);
}
