/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/13 17:01:05 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		sphere_intersection(t_ray ray, t_object sphere, double *t)
{
	t_quadratic	quad;
	t_vector	dist;

	dist = sub_vectors(ray.origin, sphere.position);
	quad.a = dot_vectors(ray.direction, ray.direction);
	quad.b = 2 * dot_vectors(ray.direction, dist);
	quad.c = dot_vectors(dist, dist) - sphere.obj_prop.sphere.radius
		* sphere.obj_prop.sphere.radius;
	if (!solve_quadratic(&quad))
		return (FALSE);
	if (quad.x0 > quad.x1)
		ft_swap(&quad.x0, &quad.x1);
	if (quad.x0 < 0)
		quad.x0 = quad.x1;
	if (quad.x0 < 0)
		return (FALSE);
	*t = quad.x0;
	return (TRUE);
}
