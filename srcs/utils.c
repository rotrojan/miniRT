/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 15:43:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** If the parsing is not finished when called, this function must be called with
** is_after_parsing = 0 to call the proper function to clear the camera chain-
** linked list, since it is made circular only at the end of the parsing.
*/

void		free_scene(t_scene *scene, int is_after_parsing)
{
	if (is_after_parsing)
		ft_circularlstclear(&scene->cam_lst, &free);
	else
		ft_lstclear(&scene->cam_lst, &free);
	ft_lstclear(&scene->light_lst, &free);
	ft_lstclear(&scene->obj_lst, &free);
}

/*
** This function display the proper error message in STDERR. Check the errors.h
** for more informations.
*/

t_error		return_error(t_error num_error)
{
	static char const	*str_error[] = { NULL, NB_ARGS_ERR_STR, OPENING_ERR_STR,
		OPENING_DIR_ERR_STR, FILE_EXTENSION_ERR_STR, THIRD_ARG_ERR_STR,
		READ_ERR_STR, MALLOC_ERR_STR, WRONG_ELEM_ERR_STR, SP_POS_FMT_ERR_STR,
		SP_COL_FMT_ERR_STR, SP_LEN_FMT_ERR_STR, SP_FMT_ERR_STR,
		PL_POS_FMT_ERR_STR, PL_COL_FMT_ERR_STR, PL_ORIENT_FMT_ERR_STR,
		PL_FMT_ERR_STR, SQ_POS_FMT_ERR_STR, SQ_COL_FMT_ERR_STR,
		SQ_ORIENT_FMT_ERR_STR, SQ_LEN_FMT_ERR_STR, SQ_FMT_ERR_STR,
		CY_POS_FMT_ERR_STR, CY_COL_FMT_ERR_STR, CY_ORIENT_FMT_ERR_STR,
		CY_DIAM_FMT_ERR_STR, CY_HGHT_FMT_ERR_STR, CY_FMT_ERR_STR,
		TR_COL_FMT_ERR_STR, TR_VER_FMT_ERR_STR, TR_FMT_ERR_STR,
		RES_X_FMT_ERR_STR, RES_Y_FMT_ERR_STR, RES_MISS_ERR_STR,
		RES_TWICE_ERR_STR, RES_FMT_ERR_STR, AMB_MISS_ERR_STR, AMB_TWICE_ERR_STR,
		AMB_FMT_ERR_STR, AMB_RATIO_ERR_STR, AMB_COL_ERR_STR, CAM_ERR_STR,
		CAM_POS_ERR_STR, CAM_ORIENT_ERR_STR, CAM_FOV_ERR_STR, LIGHT_ERR_STR,
		LIGHT_POS_ERR_STR, LIGHT_INTENS_ERR_STR, LIGHT_COL_ERR_STR,
		NB_CAM_ERR_STR, BMP_ERR_STR, MLX_HOOKS_ERR_STR};

	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd((char*)str_error[num_error], STDERR_FILENO);
	return (EXIT_FAILURE);
}
