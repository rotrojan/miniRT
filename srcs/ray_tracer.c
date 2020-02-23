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

/*************************************INIT*************************************/

void	init_sphere(t_sphere *sphere)
{
	sphere->center = get_vector(0.0f, 0.0f, -55.0f);
	sphere->radius = 20.0f;
	sphere->color[0] = 1.0f;
	sphere->color[1] = 0.0f;
	sphere->color[2] = 1.0f;
}

void		init_spot(t_light *spot)
{
	spot->position = get_vector(-30.0f, 30.0f, -45.0f);
	spot->intensity = 1.0f;
}

t_ray	init_ray_direction(int i, int j, t_camera *cam, t_application *app)
{
	t_ray		current;

	current.origin = get_vector(0, 0, 0);
	current.direction.x = (2.0f * (((double)i + 0.5f) / (double)app->win_width) - 1.0f)
		* (double)(app->win_width / (double)app->win_height) * tanf(cam->fov / 2.0f);
	current.direction.y = (1.0f - 2.0f * (((double)j + 0.5f) / (double)app->win_height))
		* tan(cam->fov / 2.0f);
	current.direction.z = -1.0f;
	current.direction = normalized_vector(current.direction);
	return (current);
}

void	init_camera(t_camera *cam)
{
	cam->position = get_vector(0.0f, 0.0f, 0.0f);
	cam->direction = get_vector(0.0f, 0.0f, -1.0f);
	cam->fov = 60.0f * M_PI / 180.0f;
}

/******************************************************************************/

int		intersection(t_ray *current, t_sphere *sphere, double *t)
{
	t_vector	dist;
	double		b;
	double		discr;
	double		t0;
	double		t1;

	dist = sphere->center - current->origin;
	b = dot_vectors(current->direction, dist);
	discr = b * b - dot_vectors(dist, dist) + sphere->radius * sphere->radius;
	if (discr >= 0.0f)
	{
		discr = sqrtf(discr);
		t0 = b - discr;
		t1 = b + discr;
		if (t0 > 0.0f)
			*t = t0;
		else if (t1 > 0.0f)
			*t = t1;
		return (1);
	}
	return (0);
}
/*
t_vector	get_normal(t_vector *closest_intersection, t_sphere *sphere)
{
	t_vector	n;
	double		tmp;

	if (!(tmp = dot_vectors(n, n)) == 0.0f)
		return 
}
*/
int		ray_tracer(t_application *app)
{
	int			i;
	int			j;
	t_color		color_pixel = {0.0f, 0.0f, 0.0f};
	t_light		spot;
	t_sphere	sphere;
	t_camera	cam;
	t_ray		current;
	double		t;
	t_vector	closest_intersection;
	t_vector	n;

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
			if (intersection(&current, &sphere, &t))
			{
				closest_intersection = current.origin + t * current.direction;
//				n = get_normal(&closest_intersection, &sphere);
				n = normalized_vector(closest_intersection - sphere.center);
				double lambert = fminf(1, dot_vectors(n, normalized_vector(spot.position - closest_intersection)));
//				printf("%f\n", lambert);
				color_pixel[0] = (sphere.color[0] * lambert);
				color_pixel[1] = (sphere.color[1] * lambert);
				color_pixel[2] = (sphere.color[2] * lambert);
				
				put_pixel(app, i, j, color_pixel);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
