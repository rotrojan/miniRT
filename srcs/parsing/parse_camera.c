/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:22:10 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/15 17:08:59 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool		check_fov(char *fov_str)
{
	while (ft_isdigit(*fov_str))
		fov_str++;
	if (*fov_str == '.')
		fov_str++;
	if (ft_isdigit(*fov_str))
		fov_str++;
	if (*fov_str)
		return (FALSE);
	return (TRUE);
}

t_error				parse_camera(char **token_array, t_scene *scene)
{
	t_object	*camera;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (CAM_ERR);
	camera = NULL;
	if (!(camera = (t_object*)malloc(sizeof(*camera))))
		return (MALLOC_ERR);
	ft_bzero(camera, sizeof(*camera));
	if (!(parse_vector(token_array[1], &(camera->position))))
		return (free_and_return(CAM_POS_ERR, camera));
	if (!(parse_orientation(token_array[2], &camera->obj_prop.camera.orientation)))
		return (free_and_return(CAM_ORIENT_ERR, camera));
	if (!(check_fov(token_array[3])))
		return (free_and_return(CAM_FOV_ERR, camera));
	camera->obj_prop.camera.fov = ft_atod(token_array[3]);
	ft_lstadd_back(&scene->cam_lst, ft_lstnew(camera));
	return (NO_ERROR);
}
