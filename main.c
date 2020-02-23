/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/23 16:18:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	__attribute__((destructor))leaks(void)
{
	system("leaks minirt");
}

int		main(int ac, char **av)
{
	t_application	app;
	t_list		*parsed_object_list;

	if (!(check_args(ac, av)))
		return (0);
	parsed_object_list = NULL;
	if (!parser(av[1], &parsed_object_list))
		return (0);
	printf("parser ok\n");
	init_app(&app);
	apply_background(&app, 0x00000000);
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	parsed_object_list = NULL;
	ray_tracer(&app);
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	return (run_application(&app));
}
