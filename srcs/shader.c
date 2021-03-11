/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:23:58 by bigo              #+#    #+#             */
/*   Updated: 2021/03/11 15:05:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		shader(t_ray current_ray, t_object closest_obj, double *t,
																t_main *main)
{
	t_vector	closest_intersection;
	t_vector	n;
	t_vector	l;
	t_color		color_pixel;
	double		tbis;
	t_ray		shadow_ray;
	t_vector current_light_position;

	t_list *current_light = main->scene.light_lst;
	color_pixel = get_color(0, 0, 0);
	closest_obj.position = closest_obj.position;
	while (current_light)
	{
		current_light_position = ((t_object*)current_light->content)->position;
		closest_intersection = add_vectors(
			scale_vector(*t, current_ray.direction),
			((t_object*)main->scene.cam_lst->content)->position);
		n = closest_obj.get_normal(closest_obj, closest_intersection);
		if (dot_vectors(current_ray.direction, n) > 0)
			n = scale_vector(-1, n);
		l = sub_vectors(current_light_position, closest_intersection);
		shadow_ray.origin = add_vectors(closest_intersection,
			scale_vector(1e-4, n));
		shadow_ray.direction = normalized_vector(
			sub_vectors(current_light_position, shadow_ray.origin));
		get_closest_intersection(shadow_ray, main, &tbis);
		if (!(tbis < norm_vector(sub_vectors(current_light_position,
			shadow_ray.origin))) && dot_vectors(n, current_ray.direction) < 0)
			color_pixel = add_colors(color_pixel,
				mix_colors(shade_color(((t_object*)current_light->content)->obj_prop.light.
				intensity / M_PI * fmax(0, fmin(1, dot_vectors(
				normalized_vector(l), n))), closest_obj.color),
				((t_object*)current_light->content)->color));
		current_light = current_light->next;
	}
	color_pixel = mix_colors(add_colors(color_pixel, shade_color(main->scene.ambient.ratio
		/  M_PI, closest_obj.color)), main->scene.ambient.color);
	return (color_pixel);
}
