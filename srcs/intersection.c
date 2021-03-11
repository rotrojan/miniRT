/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/11 14:46:16 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		solve_quadratic(t_quadratic *quad)
{
	double	discr;
	double	q;

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

t_bool		plane_intersection(t_ray ray, t_object plane, double *t)
{
	double		denom;
	t_vector	diff;

	denom = dot_vectors(plane.obj_prop.plane.normal, ray.direction);
	if (fabs(denom) > 0)
	{
		diff = sub_vectors(plane.position, ray.origin);
		*t = dot_vectors(diff, plane.obj_prop.plane.normal) / denom;
		if (*t > 0)
			return (TRUE);
	}
	return (FALSE);
}

t_bool		triangle_intersection(t_ray ray, t_object triangle, double *t)
{
	t_vector	edge1;
	t_vector	edge2;
	double		nbr[4];
	t_vector	vec[3];

	edge1 = sub_vectors(triangle.obj_prop.triangle.vertice2, triangle.position);
	edge2 = sub_vectors(triangle.obj_prop.triangle.vertice3, triangle.position);
	vec[0] = cross_vectors(ray.direction, edge2);
	nbr[0] = dot_vectors(vec[0], edge1);
	if (nbr[0] == 0)
		return (FALSE);
	nbr[1] = 1.0 / nbr[0];
	vec[1] = sub_vectors(ray.origin, triangle.position);
	nbr[2] = nbr[1] * dot_vectors(vec[0], vec[1]);
	if (nbr[2] < 0.0 || nbr[2] > 1.0)
		return (FALSE);
	vec[2] = cross_vectors(vec[1], edge1);
	nbr[3] = nbr[1] * dot_vectors(vec[2], ray.direction);
	if (nbr[3] < 0.0 || (nbr[2] + nbr[3]) > 1.0)
		return (FALSE);
	*t = nbr[1] * dot_vectors(edge2, vec[2]);
	if (*t > 0)
		return (TRUE);
	else
		return (FALSE);
}
