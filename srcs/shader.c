/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:23:58 by bigo              #+#    #+#             */
/*   Updated: 2021/03/11 18:42:41 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	shadow(t_ray shadow_ray, t_object light, t_main *main)
{
	double		tbis;

	get_closest_intersection(shadow_ray, main, &tbis);
	if (!(tbis < norm_vector(sub_vectors(light.position,
		shadow_ray.origin))))
		return (FALSE);
	return (TRUE);
}

t_ray	init_shadow_ray(t_vector closest_intersection, t_vector n,
																t_object light)
{
	t_ray	shadow_ray;

	shadow_ray.origin = add_vectors(closest_intersection,
		scale_vector(1e-4, n));
	shadow_ray.direction = normalized_vector(
		sub_vectors(light.position, shadow_ray.origin));
	return (shadow_ray);
}

t_color	colorize_pixel(t_color color_pixel, t_list *current_light,
									t_object closest_obj, double dot_product)
{
	t_color colored;

	colored = add_colors(color_pixel, mix_colors(shade_color(
		((t_object*)current_light->content)->obj_prop.light.intensity / M_PI *
		fmax(0, fmin(1, dot_product)), closest_obj.color),
		((t_object*)current_light->content)->color));
	return (colored);
}

t_color	shader(t_ray current_ray, t_object closest_obj,
									t_vector closest_intersection, t_main *main)
{
	t_vector	n;
	t_vector	l;
	t_color		color_pixel;
	t_list		*current_light;
	t_ray		shadow_ray;

	current_light = main->scene.light_lst;
	color_pixel = get_color(0, 0, 0);
	while (current_light)
	{
		n = closest_obj.get_normal(closest_obj, closest_intersection);
		if (dot_vectors(current_ray.direction, n) > 0)
			n = scale_vector(-1, n);
		l = sub_vectors(((t_object*)current_light->content)->position,
			closest_intersection);
		shadow_ray = init_shadow_ray(closest_intersection, n,
				*((t_object*)current_light->content));
		if (!(shadow(shadow_ray, *((t_object*)current_light->content), main)))
			color_pixel = colorize_pixel(color_pixel, current_light,
				closest_obj, dot_vectors(normalized_vector(l), n));
		current_light = current_light->next;
	}
	color_pixel = mix_colors(add_colors(color_pixel, shade_color(main->scene.
		ambient.ratio / M_PI, closest_obj.color)), main->scene.ambient.color);
	return (color_pixel);
}
