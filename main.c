/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/20 21:25:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int ac, char **av)
{
	t_application	app;
	t_point			dot;
	t_vector		vec;

	(void)ac;
	(void)av;
	init_app(&app);
	apply_background(&app, 0x00000000);
	render(&app);
	dot.x = 200;
	dot.y = 300;
	vec.x = 50;
	vec.y = 50;
	draw_circle(&app, dot, vec, 0x00ff00ff);
	draw_rectangle(&app, dot, vec, 0x00ffffff);
	render(&app);
	return (run_application(&app));
}
