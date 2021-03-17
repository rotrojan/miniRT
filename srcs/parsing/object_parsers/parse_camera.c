/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:22:10 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 15:06:53 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Since the camera is the only object with a data such as the Field Of View (a
** floating point number in the range ]0-180[) the check_fov function can be
** static here.
*/

static t_bool		check_fov(char *fov_str)
{
	char	*tmp;

	tmp = fov_str;
	if (!(check_double(&tmp)))
		return (FALSE);
	if (*tmp)
		return (FALSE);
	return (TRUE);
}

t_error				parse_camera(char **token_array, t_main *main)
{
	t_object	*camera;
	t_list		*link;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (CAM_ERR);
	camera = NULL;
	if (!(camera = (t_object*)malloc(sizeof(*camera))))
		return (MALLOC_ERR);
	camera->obj_type = CAMERA;
	if (!(parse_vector(token_array[1], &(camera->position))))
		return (free_and_return(CAM_POS_ERR, camera));
	if (!(parse_orientation(token_array[2],
		&camera->obj_prop.camera.orientation)))
		return (free_and_return(CAM_ORIENT_ERR, camera));
	if (!(check_fov(token_array[3])))
		return (free_and_return(CAM_FOV_ERR, camera));
	camera->obj_prop.camera.fov = ft_atod(token_array[3]);
	if (camera->obj_prop.camera.fov >= 180 || camera->obj_prop.camera.fov <= 0)
		return (free_and_return(CAM_FOV_ERR, camera));
	if (!(link = ft_lstnew(camera)))
		return (free_and_return(MALLOC_ERR, camera));
	ft_lstadd_back(&main->scene.cam_lst, link);
	return (NO_ERROR);
}
