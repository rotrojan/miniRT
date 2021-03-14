/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 13:37:12 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
