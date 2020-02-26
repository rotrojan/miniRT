/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:52:24 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 04:12:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** void	__attribute__((destructor))leaks(void)
** {
** 	system("leaks minirt");
** }
*/

int		main(int ac, char **av)
{
	t_mlx		mlx;
	t_list		*obj_lst;
	int			fd;
	t_error		ret;

	obj_lst = NULL;
	if ((ret = check_args(ac, av)) != NO_ERROR)
		return (return_error(ret, &obj_lst));
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if ((ret = parser(fd, &obj_lst)))
			return (return_error(ret, &obj_lst));
		close(fd);
	}
	else
		return (return_error(OPENING_ERR, &obj_lst));
	ft_lstclear(&obj_lst, &free);
	init_mlx(&mlx);
	apply_background(&mlx, 0x00000000);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	ray_tracer(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	return (run_mlx(&mlx));
}
