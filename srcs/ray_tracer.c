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
	printf("%f %f %f %f\n", mat[0][0], mat[0][1], mat[0][2], mat[0][3]);
	printf("%f %f %f %f\n", mat[1][0], mat[1][1], mat[1][2], mat[1][3]);
	printf("%f %f %f %f\n", mat[2][0], mat[2][1], mat[2][2], mat[2][3]);
	printf("%f %f %f %f\n\n", mat[3][0], mat[3][1], mat[3][2], mat[3][3]);
}

t_matrix *look_at(t_vector from, t_vector to)
{ 
	t_vector tmp;
	t_vector forward;
	t_vector right;
	t_vector up;
	t_matrix *cam_to_world;
 
	tmp = get_vector(0, 1, 0);
	forward = norm_vector(from - to);
	right = cross_vectors(norm_vector(tmp), forward);
	up = cross_vectors(forward, right);
	if (!(cam_to_world = (t_matrix*)malloc(sizeof(t_matrix))))
		return (NULL);
	*cam_to_world[0][0] = right.x;
	*cam_to_world[0][1] = right.y;
	*cam_to_world[0][2] = right.z;
	*cam_to_world[1][0] = up.x;
	*cam_to_world[1][1] = up.y;
	*cam_to_world[1][2] = up.z;
	*cam_to_world[2][0] = forward[0];
	*cam_to_world[2][1] = forward[1];
	*cam_to_world[2][2] = forward[2];
	*cam_to_world[3][0] = from[0];
	*cam_to_world[3][1] = from[1];
	*cam_to_world[3][2] = from[2];
	*cam_to_world[0][3] = 0;
	*cam_to_world[1][3] = 0;
	*cam_to_world[2][3] = 0;
	*cam_to_world[3][3] = 1;
	print_matrix(*cam_to_world);
	return (cam_to_world);
} 

t_ray	init_ray_direction(int i, int j, t_main *main)
{
	t_ray		current_ray;
	t_camera	*cam;
//	static int	index_cam = 0;

	cam = (t_camera*)main->scene.cam_lst->content;
	current_ray.origin = cam->position;
//	if (!((&scene->camera)[index_cam]))
//		index_cam = 0;
	current_ray.direction.x = (2.0 * ((i + 0.5) / main->mlx.win_width) - 1.0)
		* ((double)main->mlx.win_width / main->mlx.win_height)
		* tan((cam->fov * M_PI / 180.0) / 2.0);
	current_ray.direction.y = (1.0 - 2.0 * ((j + 0.5) / main->mlx.win_height))
		* tan((cam->fov * M_PI / 180.0) / 2.0);
	current_ray.direction.z = -1.0;
	current_ray.direction = normalized_vector(current_ray.direction);
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


t_bool		ray_tracer(t_main *main)
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
	current_cam = main->scene.cam_lst;
	while (current_cam)
	{
		if (!(cam_to_world = look_at(((t_object*)current_cam->content)->position,
			((t_object*)current_cam->content)->obj_prop.camera.orientation)))
			return_error(MALLOC_ERR);
		/* print_matrix(*cam_to_world); */
		
		while (j < main->mlx.win_height)
		{
			while (i < main->mlx.win_width)
			{
				current = init_ray_direction(i, j, main);
				t = 0.0;
				if ((closest_obj = get_closest_intersection(&current, &main->scene, &t)))
				{
					closest_intersection = current.origin + t * current.direction;
					n = normalized_vector(closest_intersection - closest_obj->position);
					lambert = fmax(0, fmin(1, dot_vectors(n, normalized_vector(((t_light*)main->scene.light_lst->content)->position - closest_intersection))));
					color_pixel[0] = closest_obj->color[0] * lambert;
					color_pixel[1] = closest_obj->color[1] * lambert;
					color_pixel[2] = closest_obj->color[2] * lambert;
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
	return (TRUE);
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
