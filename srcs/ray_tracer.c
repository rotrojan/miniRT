/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:40:03 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/26 05:05:37 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define RAY_T_MIN 0.0001f
#define RAY_T_MAX 1.0e30f

#include <stdio.h>

int		intersects(t_ray ray, t_sphere sphere)
{
	double		a;
	double		b;
	double		c;
	t_vector	dist;
	double		discr;

	dist = (t_vector)sphere.center;
	a = dot_vectors(ray.direction, ray.direction);
	b = 2 * dot_vectors(ray.direction, dist);
	c = dot_vectors(dist, dist) - sphere.radius * sphere.radius;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	double t1 = (- b + sqrt(discr) / (2 * a));
	double t2 = (- b - sqrt(discr) / (2 * a));
	if (t2 < t1)
		return (1);
	return (0);
}

int		ray_tracer(t_application *app)
{
	int			i;
	int			j;
	t_ray		current;
	double		fov;
	t_sphere	sphere;

	i = 0;
	j = 0;
	fov = 60 * M_PI / 180;
	sphere.center.x = 0;
	sphere.center.y = 0;
	sphere.center.z = -55;
	sphere.radius = 20;
	while (j < WIN_Y)
	{
		while (i < WIN_X)
		{
			ft_bzero(&current.origin, sizeof(current.origin));
			current.direction.x = i - WIN_X / 2;
			current.direction.y = j - WIN_Y / 2 ;
			current.direction.z = -WIN_X / (2 * tan(fov / 2));
			if (intersects(current, sphere))
			{
				put_pixel(app, i, j, 0x00ffffff);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
