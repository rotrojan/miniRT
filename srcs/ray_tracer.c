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

t_ray	init_ray_direction(int i, int j, t_scene *scene, t_mlx *mlx)
{
	t_ray		current;
//	static int	index_cam = 0;

	current.origin = (scene->camera)[0].position;
//	if (!((&scene->camera)[index_cam]))
//		index_cam = 0;
	current.direction.x = (2.0 * (((double)i + 0.5) / (double)mlx->win_width)
		- 1.0) * (double)(mlx->win_width / (double)mlx->win_height)
		* tanf((scene->camera->fov * M_PI / 180) / 2.0);
	current.direction.y = (1.0 - 2.0 * (((double)j + 0.5) /
		(double)mlx->win_height)) * tan((scene->camera->fov * M_PI / 180)
		/ 2.0);
	current.direction.z = -1.0;
	current.direction = normalized_vector(current.direction);
	return (current);
}

int		get_closest_intersection(t_ray *current, t_scene *scene, double *t)
{
	int				index_obj;
	int				index_closest_obj;
	double			t_closest_obj;
	t_type			type_obj;
	static t_bool	(*intersection[])(t_ray*, t_object*, double*) = {
		NULL, NULL, NULL, NULL, &sphere_intersection, &plane_intersection,
		&square_intersection, &cylinder_intersection, &triangle_intersection
	};

	index_obj = 0;
	t_closest_obj = INFINITY;
	while ((&scene->obj)[index_obj])
	{
		type_obj = scene->obj[index_obj].obj_type;
		if (intersection[type_obj](current, &scene->obj[index_obj], t))
		{
			if (*t < t_closest_obj)
			{
				t_closest_obj = *t;
				index_closest_obj = index_obj;
			}
		}
		index_obj++;
	}
	if (t_closest_obj == INFINITY)
		return (-1);
	return (index_closest_obj);
}

t_bool		ray_tracer(t_mlx *mlx, t_scene *scene)
{
	int			i;
	int			j;
	t_color		color_pixel;
	t_ray		current;
	double		t;
	t_vector	closest_intersection;
	int			closest_index;
//	t_vector	n;
//	double		lambert;

	i = 0;
	j = 0;
	ft_bzero(&color_pixel, sizeof(color_pixel));
	while (j < mlx->win_height)
	{
		while (i < mlx->win_width)
		{
			current = init_ray_direction(i, j, scene, mlx);
//			t = 0.0;
			if ((closest_index = get_closest_intersection(&current, scene, &t))
				!= -1)
			{
				closest_intersection = current.origin + t * current.direction;
//				n = normalized_vector(closest_intersection - scene->
//					obj[closest_index].position);
//				lambert = fmin(1, dot_vectors(n, normalized_vector(scene->
//					light[0].position - closest_intersection)));
				color_pixel[0] = (scene->obj[closest_index].color[0]/* * lambert*/);
				color_pixel[1] = (scene->obj[closest_index].color[1]/* * lambert*/);
				color_pixel[2] = (scene->obj[closest_index].color[2]/* * lambert*/);
				put_pixel(mlx, i, j, color_pixel);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (TRUE);
}
