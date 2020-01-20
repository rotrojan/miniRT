/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:26:38 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/20 22:45:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		key_hook(int key, t_application *app)
{
	if (key == 53)
	{
		close_application(app);
	}
	return (0);
}

int				set_mlx_hooks(t_application *app)
{
	if (!(mlx_hook(app->win_ptr, KEYPRESS, NOEVENTMASK, key_hook, app)))
		return (1);
	if (!(mlx_hook(app->win_ptr, DESTROYNOTIFY, NOEVENTMASK,
		close_application, app)))
		return (1);
	if (!(mlx_loop_hook(app->win_ptr, 0, NOEVENTMASK)))
		return (1);
	return (0);
}
