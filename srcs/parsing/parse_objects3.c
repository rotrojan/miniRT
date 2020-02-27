/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:32:23 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 23:52:23 by rotrojan         ###   ########.fr       */
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

t_error				parse_camera(char **token_array, t_list **obj_lst)
{
	t_object	*camera;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (CAM_ERR);
	if (!(camera = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	if (!(parse_vector(token_array[1], &camera->obj_prop.camera.position)))
	{
		free(camera);
		return (CAM_POS_ERR);
	}
	if (!(parse_orientation(token_array[2], &camera->obj_prop.camera.orientation)))
	{
		free(camera);
		return (CAM_ORIENT_ERR);
	}
	if (!(check_fov(token_array[3])))
	{
		free(camera);
		return (CAM_FOV_ERR);
	}
	camera->obj_prop.camera.fov = ft_atod(token_array[3]);
	ft_lstadd_front(obj_lst, ft_lstnew(camera));
	return (NO_ERROR);
}

t_error				parse_light(char **token_array, t_list **obj_lst)
{
	t_object	*light;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (LIGHT_ERR);
	if (!(light = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	if (!(parse_vector(token_array[1], &light->obj_prop.light.position)))
	{
		free(light);
		return (LIGHT_POS_ERR);
	}
	if (!(parse_ratio(token_array[2], &light->obj_prop.light.intensity)))
	{
		free(light);
		return (LIGHT_INTENS_ERR);
	}
	if (!(parse_color(token_array[3], &light->obj_prop.light.color)))
	{
		free(light);
		return (LIGHT_INTENS_ERR);
	}
	ft_lstadd_front(obj_lst, ft_lstnew(light));
	return (NO_ERROR);
}
