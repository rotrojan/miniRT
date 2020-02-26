/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:07:01 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 04:10:19 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_error		check_resolution(char **token_array, t_list **obj_lst)
{
	t_list		*current_link;
	char		*tmp;

	current_link = *obj_lst;
	while (current_link)
	{
		if (((t_object*)(current_link->content))->obj_type == RESOLUTION)
			return (RES_TWICE_ERR);
		current_link = current_link->next;
	}
	if (!token_array[1] || !token_array[2] || token_array[3])
		return (RES_FMT_ERR);
	tmp = token_array[1];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (RES_X_FMT_ERR);
	tmp = token_array[2];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (RES_Y_FMT_ERR);
	return (NO_ERROR);
}

t_error				parse_resolution(char **token_array, t_list **obj_lst)
{
	t_object	*resolution;
	t_error		ret;

	if ((ret = check_resolution(token_array, obj_lst)) != NO_ERROR)
		return (ret);
	if (!(resolution = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	resolution->obj_type = RESOLUTION;
	if ((resolution->obj_prop.resolution.width = ft_atoi(token_array[1])) <= 0)
	{
		free(resolution);
		return (RES_X_FMT_ERR);
	}
	if ((resolution->obj_prop.resolution.width = ft_atoi(token_array[2])) <= 0)
	{
		free(resolution);
		return (RES_X_FMT_ERR);
	}
	ft_lstadd_front(obj_lst, ft_lstnew(resolution));
	return (NO_ERROR);
}

t_error				parse_ambient(char **token_array, t_list **obj_lst)
{
	t_object	*ambient;

	if (!token_array[1] || !token_array[2] || token_array[3])
		return (AMB_FMT_ERR);
	ambient = NULL;
	if (!(ambient == (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	if (!(parse_ratio(token_array[1], &ambient->obj_prop.ambient.ratio)))
	{
		free(ambient);
		return (AMB_RATIO_ERR);
	}
	if (!(parse_color(token_array[2], &ambient->obj_prop.ambient.color)))
	{
		free(ambient);
		return (AMB_COL_ERR);
	}
	ft_lstadd_front(obj_lst, ft_lstnew(ambient));
	return (NO_ERROR);
}

t_error				parse_camera(char **token_array, t_list **obj_lst)
{
	(void)token_array;
	(void)obj_lst;
	return (NO_ERROR);
}

t_error				parse_light(char **token_array, t_list **obj_lst)
{
	(void)token_array;
	(void)obj_lst;
	return (NO_ERROR);
}
