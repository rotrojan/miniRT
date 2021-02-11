/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:27:20 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/11 17:35:38 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		parse_plane(char **token_array, t_scene *scene)
{
	t_object	*plane;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (PL_FMT_ERR);
	if (!(plane = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	plane->obj_type = PLANE;
	if (!(parse_vector(token_array[1], &plane->position)))
		return (free_and_return(PL_POS_FMT_ERR, plane));
	if (!(parse_orientation(token_array[2], &plane->obj_prop.plane.normal)))
		return (free_and_return(PL_ORIENT_FMT_ERR, plane));
	if (!(parse_color(token_array[3], &plane->color)))
		return (free_and_return(PL_COL_FMT_ERR, plane));
	ft_lstadd_front(&scene->obj_lst, ft_lstnew(plane));
	return (NO_ERROR);
}
