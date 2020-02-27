/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/27 17:30:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** void	__attribute__((destructor))leaks(void)
** {
** 	system("leaks minirt");
** }
*/



t_error		from_lst_to_struct(t_list **obj_lst, t_scene *scene, t_mlx *mlx)
{
	t_list		*current_link;
	int			nb_cameras;
	int			nb_lights;
	int			nb_objects;

	current_link = *obj_lst;
	while (current_link)
	{
		if (((t_object*)current_link->content)->obj_type == RESOLUTION)
		{
			mlx->win_width = fmin(WIN_X_MAX,
				((t_object*)current_link->content)->obj_prop.resolution.width);
			mlx->win_height = fmin(WIN_Y_MAX,
				((t_object*)current_link->content)->obj_prop.resolution.height);
		}
		else if (((t_object*)current_link->content)->obj_type == AMBIENT)
		{
			scene->ambient.ratio =
				((t_object*)current_link->content)->obj_prop.ambient.ratio;
			scene->ambient.color =
				((t_object*)current_link->content)->obj_prop.ambient.color;
		}
		else if (((t_object*)current_link->content)->obj_type == CAMERA)
		{
		}
	}
	return (NO_ERROR);
}

t_error		lexer_parser(int ac, char **av, t_scene *scene, t_mlx *mlx)
{
	t_list		*obj_lst;
	int			fd;
	t_error		ret;
	t_nb_elem	to_malloc;

	obj_lst = NULL;
	if ((ret = check_args(ac, av)) != NO_ERROR)
		return (ret);
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if ((ret = parser(fd, &obj_lst)))
			return (ret);
		close(fd);
	}
	else
		return (OPENING_ERR);
	if ((ret = from_lst_to_struct(&obj_lst, scene, mlx)) != NO_ERROR)
		return (ret);
	ft_lstclear(&obj_lst, &free);
	return (NO_ERROR);
}

int			main(int ac, char **av)
{
	t_mlx		mlx;
	t_scene		scene;
	t_error		ret;

	if ((ret = lexer_parser(ac, av, &scene, &mlx)) != NO_ERROR)
		return (return_error(ret));
	init_mlx(&mlx);
	ray_tracer(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	return (run_mlx(&mlx));
}
