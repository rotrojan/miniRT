
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/17 13:01:22 by bigo             ###   ########.fr       */
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
	(void)square;
	return (get_vector(0, 0, 0));
}

 t_vector	cylinder_normal(t_object cylinder, t_vector point)
{
	(void)point;
	(void)cylinder;
	return (get_vector(0, 0, 0));
}

 t_vector	triangle_normal(t_object triangle, t_vector point)
{
	(void)point;
	(void)triangle;
	return (get_vector(0, 0, 0));
}
