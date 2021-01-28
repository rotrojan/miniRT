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

void	print_matrix(t_matrix mat)
{
	printf("%.3f %.3f %.3f %.3f\n", mat[0][0], mat[0][1], mat[0][2], mat[0][3]);
	printf("%.3f %.3f %.3f %.3f\n", mat[1][0], mat[1][1], mat[1][2], mat[1][3]);
	printf("%.3f %.3f %.3f %.3f\n", mat[2][0], mat[2][1], mat[2][2], mat[2][3]);
	printf("%.3f %.3f %.3f %.3f\n", mat[3][0], mat[3][1], mat[3][2], mat[3][3]);
	printf("\n");
}

void	look_at(t_vector from, t_vector to, t_matrix *cam_to_world)
{ 
	t_vector tmp;
	t_vector forward;
	t_vector right;
	t_vector up;
 
	ft_bzero(cam_to_world, sizeof(*cam_to_world));
	tmp = get_vector(0, 1, 0);
	forward = normalized_vector(sub_vectors(from, to));
	right = cross_vectors(normalized_vector(tmp), forward);
	up = cross_vectors(forward, right);
	*(cam_to_world[0][0]) = right.x;
	*(cam_to_world[0][1]) = right.y;
	*(cam_to_world[0][2]) = right.z;
	*(cam_to_world[0][3]) = 0;
	print_matrix(*cam_to_world);
	*cam_to_world[1][0] = up.x;
	*cam_to_world[1][1] = up.y;
	*cam_to_world[1][2] = up.z;
	*cam_to_world[1][3] = 0;
	*cam_to_world[2][0] = forward.x;
	*cam_to_world[2][1] = forward.y;
	*cam_to_world[2][2] = forward.z;
	*cam_to_world[2][3] = 0;
	*cam_to_world[3][0] = from.x;
	*cam_to_world[3][1] = from.y;
	*cam_to_world[3][2] = from.z;
	*cam_to_world[3][3] = 1;
} 

t_ray	init_ray_direction(int i, int j, t_main *main, t_matrix cam_to_world)
{
	t_ray		current_ray;
	t_object	*cam;
//	static int	index_cam = 0;

	cam = (t_object*)main->scene.cam_lst->content;
	current_ray.origin = cam->position;
//	if (!((&scene->camera)[index_cam]))
//		index_cam = 0;
	current_ray.direction.x = (2.0 * ((i + 0.5) / main->mlx.win_width) - 1.0)
		* ((double)main->mlx.win_width / main->mlx.win_height)
		* tan((cam->obj_prop.camera.fov * M_PI / 180.0) / 2.0);
	current_ray.direction.y = (1.0 - 2.0 * ((j + 0.5) / main->mlx.win_height))
		* tan((cam->obj_prop.camera.fov * M_PI / 180.0) / 2.0);
	current_ray.direction.z = -1.0;
	current_ray.direction = normalized_vector(vec_matrix(current_ray.direction, cam_to_world));
	return (current_ray);
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


t_error		ray_tracer(t_main *main)
{
	int			i;
	int			j;
	t_color		color_pixel;
	t_ray		current;
	double		t;
	t_vector	closest_intersection;
	t_object	*closest_obj;
	t_list		*current_cam;
	t_vector	n;
	double		lambert;
	t_matrix	*cam_to_world;

	i = 0;
	j = 0;
	ft_bzero(&color_pixel, sizeof(color_pixel));
	cam_to_world = NULL;
	cam_to_world = (t_matrix*)malloc(sizeof(*cam_to_world));
	if (cam_to_world == NULL)
		return (return_error(MALLOC_ERR));
	current_cam = main->scene.cam_lst;
	while (current_cam)
	{
		printf("position cam = %f %f %f\n", ((t_object*)current_cam->content)->position.x, ((t_object*)current_cam->content)->position.y, ((t_object*)current_cam->content)->position.z);
		printf("orientation cam = %f %f %f\n", ((t_object*)current_cam->content)->obj_prop.camera.orientation.x, ((t_object*)current_cam->content)->obj_prop.camera.orientation.y, ((t_object*)current_cam->content)->obj_prop.camera.orientation.z);
		look_at(((t_object*)current_cam->content)->position,
			((t_object*)current_cam->content)->obj_prop.camera.orientation,
			cam_to_world);
		print_matrix(*cam_to_world);
		
		while (j < main->mlx.win_height)
		{
			while (i < main->mlx.win_width)
			{
				current = init_ray_direction(i, j, main, *cam_to_world);
				t = 0.0;
				if ((closest_obj = get_closest_intersection(&current, &main->scene, &t)))
				{
					closest_intersection = add_vectors(current.origin, get_vector(t * current.direction.x, t * current.direction.y, t * current.direction.z));
					n = normalized_vector(sub_vectors(closest_intersection, closest_obj->position));
					lambert = fmax(0, fmin(1, dot_vectors(n, normalized_vector(sub_vectors(((t_light*)main->scene.light_lst->content)->position, closest_intersection)))));
					color_pixel.r = closest_obj->color.r * lambert;
					color_pixel.g = closest_obj->color.g * lambert;
					color_pixel.b = closest_obj->color.b * lambert;
					put_pixel(&main->mlx, i, j, color_pixel);
				}
				i++;
			}
			i = 0;
			j++;
		}
		free(cam_to_world);
		current_cam = current_cam->next;
	}
	return (NO_ERROR);
}
/*
void	browse_images(t_scene *scene, t_mlx *mlx);
{
	t_list	current_cam;

	current_cam = scene->cam_lst;
	while (current_cam)
	{
		ray_tracer()
		current_cam = current_cam->next;
	}

}
*/
