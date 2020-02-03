/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:40:03 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/30 13:33:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define RAY_T_MIN 0.0001f
#define RAY_T_MAX 1.0e30f

float	intersects(t_ray ray, t_sphere sphere, t_vector *p, t_vector *n)
{
	float		a;
	float		b;
	float		c;
	t_vector	dist;
	float		discr;
	float		t1;
	float		t2;

	dist = (t_vector)sphere.center;
	a = 1;//dot_vectors(ray.direction, ray.direction);
	b = 2 * dot_vectors(ray.direction, ray.origin - sphere.center);
	c = norm_square_vector(ray.origin - dist) - sphere.radius * sphere.radius;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	t1 = (- b - sqrt(discr) / (2 * a));
	t2 = (- b + sqrt(discr) / (2 * a));
	if (t2 < 0)
		return (0);
	float t = t1 > 0 ? t1 : t2;
	*p = ray.origin + ray.direction * t;
	*n = normalized_vector(*p - sphere.center);
	return (t);
}

void	init_sphere(t_sphere *sphere)
{
	sphere->center = (t_point)get_vector(0, 0, -55);
	sphere->radius = 20;
}

void		init_spot(t_light *spot)
{
	spot->position = (t_point)get_vector(50, 50, -55);
	spot->intensity = 1;
}

t_ray	init_ray_direction(int i, int j, t_camera *cam, t_application *app)
{
	t_ray		current;

	current.direction.x = (2 * ((i + 0.5) / app->win_width) - 1)
		* (app->win_width / (float)app->win_height) * tan(cam->fov / 2);
	current.direction.y = (1 - 2 * ((j + 0.5) / app->win_height))
		* tan(cam->fov / 2);
	current.direction.z = -1;
	current.direction = normalized_vector(current.direction);
	return (current);
}

void	init_camera(t_camera *cam)
{
	cam->position = (t_point)get_vector(0, 0, 0);
	cam->direction = get_vector(0, 0, -1);
	cam->fov = 60 * M_PI / 180;
}

int		ray_tracer(t_application *app)
{
	int			i, j;
	t_ray		current;
	t_sphere	sphere;
	t_light		spot;
	t_camera	cam;
	t_vector	n, p;
	float		t;

	i = 0;
	j = 0;
	init_sphere(&sphere);
	init_spot(&spot);
	init_camera(&cam);
	while (j < app->win_height)
	{
		while (i < app->win_width)
		{
			current = init_ray_direction(i, j, &cam, app);
			t_color color = {0, 1, 1};
			color = color * (1 - fmin(1, (dot_vectors(p - spot.position, n)) / 100)) * spot.intensity;
			if ((t = intersects(current, sphere, &p, &n)))
				put_pixel(app, i, j, color);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}