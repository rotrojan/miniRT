/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/09 22:18:34 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool solve_quadratic(t_quadratic *quad)
{
	double discr;
	double q;

	discr = quad->b * quad->b - 4 * quad->a * quad->c;
	if (discr < 0)
		return (FALSE);
	else if (discr == 0)
	{
		quad->x0 = -0.5 * (quad->b / quad->a);
		quad->x1 = quad->x0;
	}
	else
	{
		if (quad->b > 0)
			q = -0.5 * (quad->b + sqrt(discr));
		else
			q = -0.5 * (quad->b + sqrt(discr));
		quad->x0 = q / quad->a;
		quad->x1 = quad->c / q;
	}
	if (quad->x0 > quad->x1)
		ft_swap(&quad->x0, &quad->x1);
	return (TRUE);
}

t_bool		sphere_intersection(t_ray ray, t_object sphere, double *t)
{
	t_quadratic quad;
	t_vector dist;

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

t_bool		plane_intersection(t_ray ray, t_object plane, double *t)
{
	double		denom;
	t_vector	diff;

	denom = dot_vectors(plane.obj_prop.plane.normal, ray.direction);
	if (fabs(denom) > 0)
	{
		diff =  sub_vectors(plane.position, ray.origin); 
		*t = dot_vectors(diff, plane.obj_prop.plane.normal) / denom;
		if (*t > 0)
			return (TRUE);
	}
	return (FALSE);
}

t_bool		square_intersection(t_ray ray, t_object square, double *t)
{
	t_vector tmp;
	t_vector height[2];
	double proj[2];
	t_vector intersection_point;
	t_vector v;
	t_vector corner[3];

	if (!(plane_intersection(ray, square, t)))
		return (FALSE);
	if (square.obj_prop.square.normal.x == 0
		&& (square.obj_prop.square.normal.y == 1
		|| square.obj_prop.square.normal.y == -1)
		&& square.obj_prop.square.normal.z == 0)
		tmp = get_vector(1, 0, 0);
	else
		tmp = get_vector(0, 1, 0);
	intersection_point = add_vectors(
		ray.origin, scale_vector(*t, ray.direction));
	height[0] = cross_vectors(tmp, square.obj_prop.square.normal);
	height[1] = cross_vectors(height[0], square.obj_prop.square.normal);
	/* height[0] = scale_vector(0.5, height[0]); */
	/* height[1] = scale_vector(0.5, height[1]); */
	corner[0] = sub_vectors(sub_vectors(square.position, scale_vector(square.obj_prop.square.size / 2, height[0])), scale_vector(square.obj_prop.square.size / 2, height[1]));
	corner[1] = add_vectors(corner[0], height[0]);
	corner[2] = add_vectors(corner[0], height[1]);
	v = sub_vectors(intersection_point, corner[0]);

	proj[0] = dot_vectors(v, sub_vectors(corner[1], corner[0]));
	proj[1] = dot_vectors(v, sub_vectors(corner[2], corner[0]));

	if ((proj[0] > 0 && proj[0] < square.obj_prop.square.size)
		&& (proj[1] > 0 && proj[1] < square.obj_prop.square.size))
		return (TRUE);
	return (FALSE);
}

t_bool		cylinder_intersection(t_ray ray, t_object cylinder, double *t)
{
	(void)ray;
	(void)cylinder;
	(void)t;
	return (TRUE);
}

t_bool		triangle_intersection(t_ray ray, t_object triangle, double *t)
{
	t_vector edge1;
	t_vector edge2;
	float a,f,u,v;
	t_vector h, s, q;

	edge1 = sub_vectors(triangle.obj_prop.triangle.vertice2, triangle.position);
	edge2 = sub_vectors(triangle.obj_prop.triangle.vertice3, triangle.position);
	h = cross_vectors(ray.direction, edge2);
	a = dot_vectors(h, edge1);
	if (a == 0)
		return (FALSE);    // This ray is parallel to this triangle.
	f = 1.0/a;
	s = sub_vectors(ray.origin, triangle.position);
	u = f * dot_vectors(h, s);
	if (u < 0.0 || u > 1.0)
		return (FALSE);
	q = cross_vectors(s, edge1);
	v = f * dot_vectors(q, ray.direction);
	if (v < 0.0 || (u + v) > 1.0)
		return (FALSE);
	// At this stage we can compute t to find out where the intersection point is on the line.
	*t = f * dot_vectors(edge2, q);
	if (*t > 0) // ray intersection
		return (TRUE);
	else // This means that there is a line intersection but not a ray intersection.
		return (FALSE);
}
