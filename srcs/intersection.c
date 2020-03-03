/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 01:06:07 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		sphere_intersection(t_ray *current, t_object *sphere, double *t)
{
	t_vector	dist;
	double		b;
	double		discr;
	double		t0;
	double		t1;

	dist = sphere->position - current->origin;
	b = dot_vectors(current->direction, dist);
	discr = b * b - dot_vectors(dist, dist) + sphere->obj_prop.sphere.radius
		* sphere->obj_prop.sphere.radius;
	if (discr >= 0.0)
	{
		discr = sqrt(discr);
		t0 = b - discr;
		t1 = b + discr;
		if (t0 > 0.0)
			*t = t0;
		else if (t1 > 0.0)
			*t = t1;
		return (TRUE);
	}
	return (FALSE);
}

t_bool		plane_intersection(t_ray *current, t_object *plane, double *t)
{
	(void)current;
	(void)plane;
	(void)t;
	return (TRUE);
}

t_bool		square_intersection(t_ray *current, t_object *square, double *t)
{
	(void)current;
	(void)square;
	(void)t;
	return (TRUE);
}

t_bool		cylinder_intersection(t_ray *current, t_object *cylinder, double *t)
{
	(void)current;
	(void)cylinder;
	(void)t;
	return (TRUE);
}

t_bool		triangle_intersection(t_ray *current, t_object *triangle, double *t)
{
	(void)current;
	(void)triangle;
	(void)t;
	return (TRUE);
}
