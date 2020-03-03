/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 05:51:18 by rotrojan         ###   ########.fr       */
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
	int			i;

	i = 0;
	printf("== Ambient ==\n");
	printf("Intensity = %f\n", scene->ambient.ratio);
	printf("Color = %f,%f,%f\n", scene->ambient.color[0],
		scene->ambient.color[1], scene->ambient.color[2]);
	printf("\n");
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
			printf("%p\n", (&scene->obj)[i]);
}

int			main(int ac, char **av)
{
	t_mlx		mlx;
	t_scene		scene;
	t_error		ret;

	if ((ret = open_and_parse_file(ac, av, &scene, &mlx)) != NO_ERROR)
		return (return_error(ret));
	print_objs(&scene);
	init_mlx(&mlx);
	ray_tracer(&mlx, &scene);
	free_scene(&scene);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	return (run_mlx(&mlx));
}
