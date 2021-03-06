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

void	print_camera(t_scene *scene)
{
	t_list *current;

	current = scene->cam_lst;
	printf("== Camera == {%p}\n", current);
	printf("position : x = %f, y = %f, z = %f\n",
		((t_object*)current->content)->position.x,
		((t_object*)current->content)->position.y,
		((t_object*)current->content)->position.z);
	printf("orientation : x = %f, y = %f, z = %f\n",
		((t_object*)current->content)->obj_prop.camera.orientation.x,
		((t_object*)current->content)->obj_prop.camera.orientation.y,
		((t_object*)current->content)->obj_prop.camera.orientation.z);
	printf("fov : %f\n", ((t_object*)current->content)->obj_prop.camera.fov);
	printf("\n");
}

/* void	print_matrix(t_matrix mat) */
/* { */
	/* printf("%.3f %.3f %.3f %.3f\n", mat[0], mat[1], mat[2], mat[3]); */
	/* printf("%.3f %.3f %.3f %.3f\n", mat[4], mat[5], mat[6], mat[7]); */
	/* printf("%.3f %.3f %.3f %.3f\n", mat[8], mat[9], mat[10], mat[11]); */
	/* printf("%.3f %.3f %.3f %.3f\n", mat[12], mat[13], mat[14], mat[15]); */
	/* printf("\n"); */
/* } */

void	set_coordinate_system(t_vector *forward, t_vector *right, t_vector *up,
		t_vector *cam_orientation)
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

void	look_at(t_object *cam)
{ 
	t_vector forward;
	t_vector right;
	t_vector up;

	set_coordinate_system(&forward, &right, &up,
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

t_ray	init_ray_direction(int i, int j, t_main *main)
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
	current_ray.origin = vec_matrix(get_vector(0, 0, 0),
		((t_object*)main->scene.cam_lst->content)->
		obj_prop.camera.cam_to_world);
	current_ray.direction = normalized_vector(sub_vectors(current_ray.direction,
		current_ray.origin));
	return (current_ray);
}

t_object	*get_closest_intersection(t_ray ray, t_main *main, double *t)
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

t_color		shader(t_ray current_ray, t_object closest_obj, double *t,
																t_main *main)
{
	t_vector	closest_intersection;
	t_vector	n;
	t_vector	l;
	t_color		color_pixel;
	double		tbis;
	t_ray		shadow_ray;
	t_vector current_light_position;

	t_list *current_light = main->scene.light_lst;
	color_pixel = get_color(0, 0, 0);
	while (current_light)
	{
		current_light_position = sub_vectors(
			((t_object*)current_light->content)->position,
			((t_object*)main->scene.cam_lst->content)->position
		);
		closest_intersection = scale_vector(*t, current_ray.direction);
		closest_obj.position = sub_vectors(
			closest_obj.position,
			((t_object*)main->scene.cam_lst->content)->position
		);
		n = closest_obj.get_normal(closest_obj, closest_intersection);
		l = sub_vectors(current_light_position, closest_intersection);
		shadow_ray.origin = add_vectors(
			add_vectors(
				closest_intersection,
				((t_object*)main->scene.cam_lst->content)->position
			),
			scale_vector(1e-10, n)
		);
		shadow_ray.direction = sub_vectors(
			current_light_position,
			shadow_ray.origin
		);
		get_closest_intersection(shadow_ray, main, &tbis);
		if (!(tbis * tbis < norm_square_vector(shadow_ray.direction)))
			color_pixel = add_colors(color_pixel, shade_color(fmax(0, fmin(1, dot_vectors(normalized_vector(l), n))), closest_obj.color));
		/*h * ((t_light*)main->scene.light_lst->content)->intensity */
		/* * ((t_light*)main->scene.light_lst->content)->color.r */
		current_light = current_light->next;
	}
	return (color_pixel);
}

t_error		ray_tracer(t_main *main)
{
	int			i;
	int			j;
	t_color		color_pixel;
	t_ray		current_ray;
	double		t;
	t_object	*closest_obj;

	i = 0;
	j = 0;
	print_camera(&main->scene);
	look_at(main->scene.cam_lst->content);
	while (j < main->mlx.win_height)
	{
		while (i < main->mlx.win_width)
		{
			current_ray = init_ray_direction(i, j, main);
			closest_obj = NULL;
			closest_obj = get_closest_intersection(current_ray, main, &t);
			/* color_pixel = get_color(0, 0, 0); */
			if (closest_obj != NULL)
			{
				color_pixel = shader(current_ray, *closest_obj, &t, main);
				/* color_pixel = closest_obj->color; */
				put_pixel(&main->mlx, i, j, color_pixel);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (NO_ERROR);
}
