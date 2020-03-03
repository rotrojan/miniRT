/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_lst_to_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:50:46 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 05:55:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	malloc_scene(t_scene *scene, t_nb_elem to_malloc)
{
	if (!(scene->camera = malloc(sizeof(t_camera) * (to_malloc.nb_cameras
		+ 1))))
		return (FALSE);
	ft_bzero(scene->camera, sizeof(t_camera) * (to_malloc.nb_cameras + 1));
	if (!(scene->light = malloc(sizeof(t_light) * (to_malloc.nb_lights + 1))))
	{
		free(scene->camera);
		scene->camera = NULL;
		return (FALSE);
	}
	ft_bzero(scene->light, sizeof(t_light) * (to_malloc.nb_lights + 1));
	if (!(scene->obj = malloc(sizeof(t_object) * (to_malloc.nb_objects + 1))))
	{
		free(scene->camera);
		scene->camera = NULL;
		free(scene->light);
		scene->light = NULL;
		return (FALSE);
	}
	ft_bzero(scene->obj, sizeof(t_object) * (to_malloc.nb_objects + 1));
	return (TRUE);
}

static void		set_struct(t_list *current_link, t_scene *scene, t_mlx *mlx,
															t_nb_elem *index)
{
	if (((t_object*)current_link->content)->obj_type == RESOLUTION)
	{
		mlx->win_width = fmin(WIN_X_MAX,
			((t_object*)current_link->content)->obj_prop.resolution.width);
		mlx->win_height = fmin(WIN_Y_MAX,
			((t_object*)current_link->content)->obj_prop.resolution.height);
		printf("res\n");
	}
	else if (((t_object*)current_link->content)->obj_type == AMBIENT)
	{
		scene->ambient = ((t_object*)current_link->content)->obj_prop.ambient;
		printf("amb\n");
	}
	else if (((t_object*)current_link->content)->obj_type == CAMERA)
	{
		scene->camera[index->nb_cameras++] =
			((t_object*)current_link->content)->obj_prop.camera;
		printf("cam\n");
	}
	else if (((t_object*)current_link->content)->obj_type == LIGHT)
	{
		scene->light[index->nb_lights++] =
			((t_object*)current_link->content)->obj_prop.light;
		printf("light\n");
	}
	else
	{
		(scene->obj)[index->nb_objects++] = (*(t_object*)current_link->content);
		printf("obj\n");
	}
}

t_error			from_lst_to_struct(t_list **obj_lst, t_scene *scene, t_mlx *mlx,
															t_nb_elem to_malloc)
{
	t_list		*current_link;
	t_nb_elem	index;
	int i = 0;

	current_link = *obj_lst;
	if (!(malloc_scene(scene, to_malloc)))
		return (MALLOC_ERR);
	ft_bzero(&index, sizeof(index));
	while (current_link)
	{
		set_struct(current_link, scene, mlx, &index);
		current_link = current_link->next;
	}
	while ((&scene->obj)[i])
	{
		if (scene->obj[i].obj_type == SPHERE)
		{
			printf("%i\n", i);
			printf("%p\n", (&scene->obj)[i]);
			printf("== Sphere ==\n");
			printf("position : x = %f, y = %f, z = %f\n",
				(&scene->obj)[i]->position.x, (&scene->obj)[i]->position.y,
				(&scene->obj)[i]->position.z);
			printf("radius : %f\n", (&scene->obj)[i]->obj_prop.sphere.radius);
			printf("\n");
		}
//		else if ()
//		{
//			obj[i].obj_type == SPHERE
//		}
		i++;
	}
	return (NO_ERROR);
}
