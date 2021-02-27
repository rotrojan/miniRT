/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/23 17:28:21 by bigo             ###   ########.fr       */
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
	quad.c = dot_vectors(dist, dist) - sphere.obj_prop.sphere.radius * sphere.obj_prop.sphere.radius;
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

/* t_bool		sphere_intersection(t_ray ray, t_object *sphere, double *t) */
/* { */
	/* t_vector	dist; */
	/* double		b; */
	/* double		discr; */
	/* double		t0; */
	/* double		t1; */

	/* dist = sub_vectors(sphere->position, current->origin); */
	/* b = dot_vectors(current->direction, dist); */
	/* discr = b * b - dot_vectors(dist, dist) + sphere->obj_prop.sphere.radius */
		/* * sphere->obj_prop.sphere.radius; */
	/* if (discr >= 0.0) */
	/* { */
		/* discr = sqrt(discr); */
		/* t0 = b - discr; */
		/* t1 = b + discr; */
		/* if (t0 > 0.0) */
			/* *t = t0; */
		/* else if (t1 > 0.0) */
			/* *t = t1; */
		/* return (TRUE); */
	/* } */
	/* return (FALSE); */
/* } */

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
	(void)ray;
	(void)square;
	(void)t;
	return (TRUE);
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
	(void)ray;
	(void)triangle;
	(void)t;
	return (TRUE);
}
