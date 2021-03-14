/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 13:32:52 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	get_centered_projection(t_vector intersection_point,
															t_object cylinder)
{
	return (add_vectors(
		cylinder.position,
		scale_vector(
			dot_vectors(
				sub_vectors(intersection_point, cylinder.position),
				cylinder.obj_prop.cylinder.orientation),
			cylinder.obj_prop.cylinder.orientation)));
}

static t_bool	finite_cylinder_intersection(t_quadratic quad, double *t,
												t_ray ray, t_object cylinder)
{
	double	cylinder_half_height;

	cylinder_half_height = cylinder.obj_prop.cylinder.height / 2;
	*t = quad.x0;
	if (norm_square_vector(sub_vectors(get_centered_projection(add_vectors(
		ray.origin, scale_vector(*t, ray.direction)), cylinder),
		cylinder.position)) > cylinder_half_height * cylinder_half_height)
	{
		*t = quad.x1;
		if (norm_square_vector(sub_vectors(get_centered_projection(
			add_vectors(ray.origin, scale_vector(*t, ray.direction)),
			cylinder), cylinder.position)) > cylinder_half_height *
			cylinder_half_height)
			return (FALSE);
	}
	return (TRUE);
}

t_bool			cylinder_intersection(t_ray ray, t_object cylinder, double *t)
{
	t_quadratic	quad;
	t_vector	vec[3];
	double		cylinder_radius;

	cylinder_radius = cylinder.obj_prop.cylinder.diameter / 2;
	vec[0] = cross_vectors(
		ray.direction, cylinder.obj_prop.cylinder.orientation);
	vec[1] = sub_vectors(ray.origin, cylinder.position);
	vec[2] = cross_vectors(vec[1], cylinder.obj_prop.cylinder.orientation);
	quad.a = dot_vectors(vec[0], vec[0]);
	quad.b = 2 * dot_vectors(vec[0], vec[2]);
	quad.c = dot_vectors(vec[2], vec[2]) - (cylinder_radius * cylinder_radius);
	if (!solve_quadratic(&quad))
		return (FALSE);
	if (quad.x0 > quad.x1)
		ft_swap(&quad.x0, &quad.x1);
	if (quad.x0 < 0 && quad.x1 < 0)
		return (FALSE);
	return (finite_cylinder_intersection(quad, t, ray, cylinder));
}
