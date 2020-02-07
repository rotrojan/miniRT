/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/07 02:39:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		apply_background(t_application *app, int color)
{
	int		nb_pixels;
	int		index_pixel;

	nb_pixels = app->win_width * app->win_height;
	index_pixel = 0;
	while (index_pixel < nb_pixels)
		app->data[index_pixel++] = color;
}

int		main(int ac, char **av)
{
	t_application	app;

	if (!check_args(ac, av))
		return (0);
	init_app(&app);
	apply_background(&app, 0x00000000);
	render(&app);
	ray_tracer(&app);
	render(&app);
	return (run_application(&app));
}
