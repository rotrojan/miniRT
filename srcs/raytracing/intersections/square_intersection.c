/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/16 13:36:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	tmp_vector(t_vector square_normal)
{
	if (square_normal.x == 0 && (square_normal.y == 1 || square_normal.y == -1)
		&& square_normal.z == 0)
		return (get_vector(1, 0, 0));
	else
		return (get_vector(0, 1, 0));
}

t_bool			square_intersection(t_ray ray, t_object square, double *t)
{
	t_vector	height[2];
	double		proj[2];
	t_vector	intersection_point;
	t_vector	v;
	t_vector	corner;

	if (!(plane_intersection(ray, square, t)))
		return (FALSE);
	intersection_point = add_vectors(
		ray.origin, scale_vector(*t, ray.direction));
	height[0] = normalized_vector(cross_vectors(tmp_vector(
		square.obj_prop.square.normal), square.obj_prop.square.normal));
	height[1] = normalized_vector(cross_vectors(height[0],
		square.obj_prop.square.normal));
	corner = sub_vectors(sub_vectors(square.position, scale_vector(
		square.obj_prop.square.size / (double)2, height[0])), scale_vector(
		square.obj_prop.square.size / (double)2, height[1]));
	v = sub_vectors(intersection_point, corner);
	proj[0] = dot_vectors(v, height[0]);
	proj[1] = dot_vectors(v, height[1]);
	if ((proj[0] > 0 && proj[0] < square.obj_prop.square.size)
		&& (proj[1] > 0 && proj[1] < square.obj_prop.square.size))
		return (TRUE);
	return (FALSE);
}
