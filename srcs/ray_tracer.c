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

	current.origin = ((t_camera*)scene->cam_lst->content)->position;
//	if (!((&scene->camera)[index_cam]))
//		index_cam = 0;
	current.direction.x = (2.0 * (((double)i + 0.5) / (double)mlx->win_width)
		- 1.0) * (double)(mlx->win_width / (double)mlx->win_height)
		* tanf((((t_camera*)scene->cam_lst->content)->fov * M_PI / 180) / 2.0);
	current.direction.y = (1.0 - 2.0 * (((double)j + 0.5) /
		(double)mlx->win_height)) * tan((((t_camera*)scene->cam_lst->content)->
		fov * M_PI / 180) / 2.0);
	current.direction.z = -1.0;
	current.direction = normalized_vector(current.direction);
	return (current);
}

t_object	*get_closest_intersection(t_ray *current, t_scene *scene, double *t)
{
	t_list			*current_link;
	double			t_closest_obj;
	t_type			type_obj;
	t_object		*closest_obj;
	static t_bool	(*intersection[])(t_ray*, t_object*, double*) = {
		NULL, NULL, NULL, NULL, &sphere_intersection, &plane_intersection,
		&square_intersection, &cylinder_intersection, &triangle_intersection
	};

	current_link = scene->obj_lst;
	t_closest_obj = INFINITY;
	while (current_link)
	{
		type_obj = ((t_object*)current_link->content)->obj_type;
		if (intersection[type_obj](current, (t_object*)current_link->content, t))
		{
			if (*t < t_closest_obj)
			{
				t_closest_obj = *t;
				closest_obj = (t_object*)current_link->content;
			}
		}
		current_link = current_link->next;
	}
	if (t_closest_obj == INFINITY)
		return (NULL);
	return (closest_obj);
}

t_bool		ray_tracer(t_mlx *mlx, t_scene *scene)
{
	int			i;
	int			j;
	t_color		color_pixel;
	t_ray		current;
	double		t;
	t_vector	closest_intersection;
	t_object	*closest_obj;
	t_vector	n;
	double		lambert;

	i = 0;
	j = 0;
	ft_bzero(&color_pixel, sizeof(color_pixel));
	while (j < mlx->win_height)
	{
		while (i < mlx->win_width)
		{
			current = init_ray_direction(i, j, scene, mlx);
//			t = 0.0;
			if ((closest_obj = get_closest_intersection(&current, scene, &t)))
			{
				closest_intersection = current.origin + t * current.direction;
				n = normalized_vector(closest_intersection - closest_obj->position);
				lambert = fmin(1, dot_vectors(n, normalized_vector(((t_light*)scene->
					light_lst->content)->position - closest_intersection)));
				color_pixel[0] = closest_obj->color[0] * lambert;
				color_pixel[1] = closest_obj->color[1] * lambert;
				color_pixel[2] = closest_obj->color[2] * lambert;
				put_pixel(mlx, i, j, color_pixel);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (TRUE);
}
