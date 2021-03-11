/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/10 23:50:45 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	sphere_normal(t_object sphere, t_vector point)
{
	return (normalized_vector(sub_vectors(point, sphere.position)));
}

t_vector	plane_normal(t_object plane, t_vector point)
{
	(void)point;
	return (normalized_vector(plane.obj_prop.plane.normal));
}

t_vector	square_normal(t_object square, t_vector point)
{
	(void)point;
	return (normalized_vector(square.obj_prop.square.normal));
}

t_vector	cylinder_normal(t_object cylinder, t_vector point)
{
	t_vector normal;
	t_vector center;

	center = add_vectors(cylinder.position,
		scale_vector(dot_vectors(sub_vectors(point, cylinder.position),
			cylinder.obj_prop.cylinder.orientation),
		cylinder.obj_prop.cylinder.orientation));
	normal = normalized_vector(sub_vectors(point, center));
	return (normal);
}

t_vector	triangle_normal(t_object triangle, t_vector point)
{
	t_vector	edge1;
	t_vector	edge2;

	(void)point;
	edge1 = sub_vectors(triangle.obj_prop.triangle.vertice2, triangle.position);
	edge2 = sub_vectors(triangle.obj_prop.triangle.vertice3, triangle.position);
	return (normalized_vector(cross_vectors(edge1, edge2)));
}
