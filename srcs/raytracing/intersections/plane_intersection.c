/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/13 17:02:18 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
