/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/11 17:45:59 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	leaks(void)
{
	system("leaks minirt");
}

void	print_objs(t_scene *scene)
{
	t_list *current;
	char	*objects[] = {NULL, NULL, NULL, NULL, "Sphere", "Plane", "Square",
		"Cylinder", "Triangle"};

	printf("== Ambient ==\n");
	printf("Intensity = %f\n", scene->ambient.ratio);
	printf("Color = %f,%f,%f\n", scene->ambient.color.r,
		scene->ambient.color.g, scene->ambient.color.b);
	printf("\n");
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
			((t_light*)current->content)->color.r,
			((t_light*)current->content)->color.g,
			((t_light*)current->content)->color.b);
		printf("\n");
		current = current->next;
	}
	current = scene->obj_lst;
	while (current)
	{
		printf("== %s == {%p}\n",objects[((t_object*)current->content)->
			obj_type], current);
		printf("position : x = %f, y = %f, z = %f\n",
			((t_object*)current->content)->position.x,
			((t_object*)current->content)->position.y,
			((t_object*)current->content)->position.z);
		printf("Color = %f,%f,%f\n",
			((t_object*)current->content)->color.r,
			((t_object*)current->content)->color.g,
			((t_object*)current->content)->color.b);
		if (((t_object*)current->content)->obj_type == SPHERE)
			printf("radius : %f\n",
				((t_object*)current->content)->obj_prop.sphere.radius);
		else if (((t_object*)current->content)->obj_type == PLANE)
			printf("normal : %f, %f, %f\n",
				((t_object*)current->content)->obj_prop.plane.normal.x,
				((t_object*)current->content)->obj_prop.plane.normal.y,
				((t_object*)current->content)->obj_prop.plane.normal.z);
		printf("\n");
		current = current->next;
	}
}

int			main(int ac, char **av)
{
	t_main		main;
	t_error		ret;
	t_list		*cam_head_lst;

	ft_bzero(&main, sizeof(main));
	main.scene.ambient.ratio = -1.0;
	cam_head_lst = main.scene.cam_lst;
	if ((ret = open_and_parse_file(ac, av, &main)) != NO_ERROR)
		return (return_error(ret));
	print_objs(&main.scene);
	init_mlx(&main.mlx);
	ray_tracer(&main);
	if (ac == 3)
	{
		if (!ft_strcmp("-save", av[2]) || !ft_strcmp("--save", av[2]))
			if ((ret = screen_shot(&main)) != NO_ERROR)
				return (return_error(ret));
	}
	else
	{
		/* main.scene.cam_lst = main.scene.cam_lst->next; */
		/* if (!main.scene.cam_lst) */
			/* main.scene.cam_lst = cam_head_lst; */
		mlx_put_image_to_window(main.mlx.mlx_ptr, main.mlx.win_ptr,
			main.mlx.img_ptr, 0, 0);
		if (!run_mlx(&main))
			return (return_error(MLX_HOOKS_ERR));
	}
	/* main.scene.cam_lst = cam_head_lst; */
	free_scene(&main.scene);
	return (EXIT_SUCCESS);
}
