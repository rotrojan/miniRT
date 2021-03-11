/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 23:40:03 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/11 18:44:45 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_coordinates_system(t_vector *forward, t_vector *right,
										t_vector *up, t_vector *cam_orientation)
{
	t_vector tmp;

	*forward = normalized_vector(scale_vector(-1, *cam_orientation));
	if (cam_orientation->x == 0
		&& (cam_orientation->y == -1 || cam_orientation->y == 1)
		&& cam_orientation->z == 0)
		*right = get_vector(1, 0, 0);
	else
	{
		tmp = get_vector(0, 1, 0);
		*right = cross_vectors(tmp, *forward);
	}
	*up = cross_vectors(*forward, *right);
}

static void		look_at(t_object *cam)
{
	t_vector forward;
	t_vector right;
	t_vector up;

	set_coordinates_system(&forward, &right, &up,
		&cam->obj_prop.camera.orientation);
	cam->obj_prop.camera.cam_to_world[0] = right.x;
	cam->obj_prop.camera.cam_to_world[1] = right.y;
	cam->obj_prop.camera.cam_to_world[2] = right.z;
	cam->obj_prop.camera.cam_to_world[3] = up.x;
	cam->obj_prop.camera.cam_to_world[4] = up.y;
	cam->obj_prop.camera.cam_to_world[5] = up.z;
	cam->obj_prop.camera.cam_to_world[6] = forward.x;
	cam->obj_prop.camera.cam_to_world[7] = forward.y;
	cam->obj_prop.camera.cam_to_world[8] = forward.z;
	cam->obj_prop.camera.cam_to_world[9] = cam->position.x;
	cam->obj_prop.camera.cam_to_world[10] = cam->position.y;
	cam->obj_prop.camera.cam_to_world[11] = cam->position.z;
}

static t_ray	init_ray_direction(int i, int j, t_main *main)
{
	t_ray		current_ray;
	t_object	*cam;

	cam = (t_object*)main->scene.cam_lst->content;
	current_ray.direction.x = (2.0 * ((i + 0.5) / main->mlx.win_width) - 1.0)
		* ((double)main->mlx.win_width / (double)main->mlx.win_height)
		* tan((cam->obj_prop.camera.fov * M_PI / 180.0) / 2.0);
	current_ray.direction.y = (1.0 - 2.0 * ((j + 0.5) / main->mlx.win_height))
		* tan((cam->obj_prop.camera.fov * M_PI / 180.0) / 2.0);
	current_ray.direction.z = (double)-1;
	current_ray.direction = vec_matrix(
		current_ray.direction,
		((t_object*)main->scene.cam_lst->content)->
		obj_prop.camera.cam_to_world);
	current_ray.origin = cam->position;
	current_ray.direction = normalized_vector(sub_vectors(current_ray.direction,
		current_ray.origin));
	return (current_ray);
}

t_object		*get_closest_intersection(t_ray ray, t_main *main, double *t)
{
	t_list			*current_obj;
	double			t_closest_obj;
	t_object		*closest_obj;

	current_obj = main->scene.obj_lst;
	t_closest_obj = INFINITY;
	while (current_obj)
	{
		if (((t_object*)current_obj->content)->intersection(
			ray, *(t_object*)current_obj->content, t))
			if (*t < t_closest_obj)
			{
				t_closest_obj = *t;
				closest_obj = (t_object*)current_obj->content;
			}
		current_obj = current_obj->next;
	}
	*t = t_closest_obj;
	if (t_closest_obj == INFINITY)
		return (NULL);
	else
		return (closest_obj);
}

t_error			ray_tracer(t_main *main)
{
	int			i;
	int			j;
	t_ray		ray;
	double		t;
	t_object	*closest_obj;

	look_at(main->scene.cam_lst->content);
	j = 0;
	while (j < main->mlx.win_height)
	{
		i = 0;
		while (i < main->mlx.win_width)
		{
			ray = init_ray_direction(i, j, main);
			closest_obj = NULL;
			if ((closest_obj = get_closest_intersection(ray, main, &t)))
				put_pixel(
					&main->mlx, i, j,
					shader(ray, *closest_obj, add_vectors(scale_vector(t,
						ray.direction), ray.origin), main));
			i++;
		}
		j++;
	}
	return (NO_ERROR);
}
