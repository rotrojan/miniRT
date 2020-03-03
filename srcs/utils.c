/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 12:17:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		del(void *content)
{
	free(content);
}

void		free_scene(t_scene *scene)
{
	ft_lstclear(&scene->cam_lst, del);
	ft_lstclear(&scene->light_lst, del);
	ft_lstclear(&scene->obj_lst, del);
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
		NB_CAM_ERR_STR
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
