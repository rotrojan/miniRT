/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/01 13:35:49 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		free_scene(t_scene *scene)
{
	ft_lstclear(&scene->cam_lst, &free);
	ft_lstclear(&scene->light_lst, &free);
	ft_lstclear(&scene->obj_lst, &free);
}

t_error		return_error(t_error num_error)
{
	static char const	*str_error[] = {
		NO_ERROR_STR,
		NB_ARGS_ERR_STR,
		OPENING_ERR_STR,
		FILE_EXTENSION_ERR_STR,
		THIRD_ARG_ERR_STR,
		READ_ERR_STR,
		MALLOC_ERR_STR,
		WRONG_ELEM_ERR_STR,
		SP_POS_FMT_ERR_STR,
		SP_COL_FMT_ERR_STR,
		SP_LEN_FMT_ERR_STR,
		SP_FMT_ERR_STR,
		PL_POS_FMT_ERR_STR,
		PL_COL_FMT_ERR_STR,
		PL_ORIENT_FMT_ERR_STR,
		PL_FMT_ERR_STR,
		RES_X_FMT_ERR_STR,
		RES_Y_FMT_ERR_STR,
		RES_TWICE_ERR_STR,
		RES_FMT_ERR_STR,
		AMB_TWICE_ERR_STR,
		AMB_FMT_ERR_STR,
		AMB_RATIO_ERR_STR,
		AMB_COL_ERR_STR,
		CAM_ERR_STR,
		CAM_POS_ERR_STR,
		CAM_ORIENT_ERR_STR,
		CAM_FOV_ERR_STR,
		LIGHT_ERR_STR,
		LIGHT_POS_ERR_STR,
		LIGHT_INTENS_ERR_STR,
		NB_CAM_ERR_STR,
		BMP_ERR_STR,
		MLX_HOOKS_ERR_STR
	};

	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd((char*)str_error[num_error], STDERR_FILENO);
	return (EXIT_FAILURE);
}

void		free_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

t_color	get_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	shade_color(double coef, t_color color)
{
	return (get_color(coef * color.r, coef * color.g, coef * color.b));
}

t_color	add_colors(t_color color1, t_color color2)
{
	return (get_color(fmin(1, fmax(0, color1.r + color2.r)),
			fmin(1, fmax(0, color1.g + color2.g)),
			fmin(1, fmax(0, color1.b + color2.b))));
}
