/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:23:58 by bigo              #+#    #+#             */
/*   Updated: 2021/03/15 00:46:38 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** To check if the pixel is in the shadow of an other object, we use the same
** intersection function that we used during the raytracing. If an intersection
** is found, we store it in tbis. If tbis is shorter than the distance between
** the light and the intesection point, the pixel is in the shadow.
** We use the square of the norm because it's less resource consuming since we
** avoid the use of a square root.
*/

static t_bool	shadow(t_ray shadow_ray, t_object light, t_main *main)
{
	double		tbis;

	get_closest_intersection(shadow_ray, main, &tbis);
	if (!(tbis * tbis < norm_square_vector(sub_vectors(light.position,
		shadow_ray.origin))))
		return (FALSE);
	return (TRUE);
}

/*
** The shadow ray origin is the intersection point, shifted along the normal by
** a very tiny bias to avoid self-intersection and "shadow acne". The direction
** of the ray points toward the light.
*/

static t_ray	init_shadow_ray(t_vector closest_intersection, t_vector n,
																t_object light)
{
	t_ray	shadow_ray;

	shadow_ray.origin = add_vectors(closest_intersection,
		scale_vector(1e-4, n));
	shadow_ray.direction = normalized_vector(sub_vectors(
		light.position, shadow_ray.origin));
	return (shadow_ray);
}

/*
** The color of each pixel is obtained by taking the color of the hit object,
** shading it according to the light intensity, mixing it with the light color,
** and adding the color resulting for each light in the scene.
*/

static t_color	colorize_pixel(t_color color_pixel, t_object current_light,
									t_object closest_obj, double dot_product)
{
	t_color colored;

	colored = add_colors(color_pixel, mix_colors(shade_color(
		current_light.obj_prop.light.intensity / M_PI *
		fmax(0, fmin(1, dot_product)), closest_obj.color),
		current_light.color));
	return (colored);
}

/*
** If an intersection is found, the normal vector n at the intersection point is
** computed. If we are inside, under, or behind the object (the scalar product
** will then be positive) we reverse it (scale it by -1). Then we compute the
** light direction vector l. We can now conpute the shadow ray to check if the
** pixel is in the shadow of another object. If it is not, the its color is
** computed according to the lambertian lighting model (the color of the pixel)
** is proportional to the cosine of the angle between the normal at the
** intersection point and the light direction, or the scalar product of n and l.
** A 1 / PI ratio is applied for a more realistic rendering.
** This process is iterated over all lights to account for their color and
** intensity, and finally the same operation is applied for the ambien lighting.
*/

t_color			shader(t_ray current_ray, t_object closest_obj,
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
		l = normalized_vector(sub_vectors(((t_object*)current_light->content)->
			position, closest_intersection));
		shadow_ray = init_shadow_ray(closest_intersection, n,
			*((t_object*)current_light->content));
		if (!(shadow(shadow_ray, *((t_object*)current_light->content), main)))
			color_pixel = colorize_pixel(color_pixel, *((t_object*)
			current_light->content), closest_obj, dot_vectors(l, n));
		current_light = current_light->next;
	}
	color_pixel = mix_colors(add_colors(color_pixel, shade_color(main->scene.
		ambient.ratio / M_PI, closest_obj.color)), main->scene.ambient.color);
	return (color_pixel);
}
