/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/19 03:45:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int ac, char **av)
{
	t_environment	env;
	t_point			dot;
	t_vector		vec;

	(void)ac;
	(void)av;
	init_env(&env);
	apply_background(&env, create_color(0, 0, 0));
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img_ptr, 0, 0);
	dot.x = 100;
	dot.y = 100;
	vec.x = 50;
	vec.y = 50;
	draw_circle(&env, dot, vec, create_color(0, 0, 255));
	draw_rectangle(&env, dot, vec, create_color(255, 0, 0));
	render(&env);
	return (run_environment(&env));
}
