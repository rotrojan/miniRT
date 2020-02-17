/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/17 01:42:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int ac, char **av)
{
	t_application	app;
	t_object		*parsed_object_list;

	if (!(check_args(ac, av)))
		return (0);
	if (!parser(av[1], &app, &parsed_object_list))
		return (0);
	init_app(&app);
	apply_background(&app, 0x00000000);
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	parsed_object_list = NULL;
	ray_tracer(&app);
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	return (run_application(&app));
}
