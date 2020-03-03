/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 11:13:43 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
void	__attribute__((destructor))leaks(void)
{
	system("leaks minirt");
}
*/

void	print_objs(t_scene *scene)
{
	t_list *current;

	printf("== Ambient ==\n");
	printf("Intensity = %f\n", scene->ambient.ratio);
	printf("Color = %f,%f,%f\n", scene->ambient.color[0],
		scene->ambient.color[1], scene->ambient.color[2]);
	printf("\n");
	current = scene->cam_lst;
	while (current)
	{
		printf("== Camera == {%p}\n", current);
		printf("position : x = %f, y = %f, z = %f\n",
			((t_camera*)current->content)->position.x,
			((t_camera*)current->content)->position.y,
			((t_camera*)current->content)->position.z);
		printf("orientation : x = %f, y = %f, z = %f\n",
			((t_camera*)current->content)->orientation.x,
			((t_camera*)current->content)->orientation.y,
			((t_camera*)current->content)->orientation.z);
		printf("fov : %f\n", ((t_camera*)current->content)->fov);
		printf("\n");
		current = current->next;
	}
	current = scene->light_lst;
	while (current)
	{
		printf("== Light == {%p}\n", current);
		printf("position : x = %f, y = %f, z = %f\n",
			((t_light*)current->content)->position.x,
			((t_light*)current->content)->position.y,
			((t_light*)current->content)->position.z);
		printf("intensity : %f\n",
			((t_light*)current->content)->intensity);
		printf("Color = %f,%f,%f\n",
			((t_light*)current->content)->color[0],
			((t_light*)current->content)->color[1],
			((t_light*)current->content)->color[2]);
		printf("\n");
		current = current->next;
	}
	current = scene->obj_lst;
	while (current)
	{
		if (((t_object*)current->content)->obj_type == SPHERE)
		{
			printf("== Sphere == {%p}\n", current);
			printf("position : x = %f, y = %f, z = %f\n",
				((t_object*)current->content)->position.x,
				((t_object*)current->content)->position.y,
				((t_object*)current->content)->position.z);
			printf("radius : %f\n",
				((t_object*)current->content)->obj_prop.sphere.radius);
			printf("Color = %f,%f,%f\n",
				((t_object*)current->content)->color[0],
				((t_object*)current->content)->color[1],
				((t_object*)current->content)->color[2]);
			printf("\n");
		}
		current = current->next;
	}
}

int			main(int ac, char **av)
{
	t_mlx		mlx;
	t_scene		scene;
	t_error		ret;

	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&scene, sizeof(scene));
	scene.ambient.ratio = -1.0;
	if ((ret = open_and_parse_file(ac, av, &scene, &mlx)) != NO_ERROR)
		return (return_error(ret));
	print_objs(&scene);
	init_mlx(&mlx);
	ray_tracer(&mlx, &scene);
	free_scene(&scene);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	return (run_mlx(&mlx));
}
