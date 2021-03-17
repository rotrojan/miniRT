/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:25:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 01:42:51 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_normal_and_intersection(t_object *cylinder)
{
	cylinder->intersection = &cylinder_intersection;
	cylinder->get_normal = &cylinder_normal;
}

t_error		parse_cylinder(char **token_array, t_main *main)
{
	t_object	*cylinder;
	t_list		*link;

	if (!token_array[1] || !token_array[2] || !token_array[3] || !token_array[4]
		|| !token_array[5] || token_array[6])
		return (CY_FMT_ERR);
	if (!(cylinder = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	cylinder->obj_type = CYLINDER;
	if (!(parse_vector(token_array[1], &cylinder->position)))
		return (free_and_return(CY_POS_FMT_ERR, cylinder));
	if (!(parse_orientation(
		token_array[2], &cylinder->obj_prop.cylinder.orientation)))
		return (free_and_return(CY_ORIENT_FMT_ERR, cylinder));
	if (!(parse_length(token_array[3], &cylinder->obj_prop.cylinder.diameter)))
		return (free_and_return(CY_DIAM_FMT_ERR, cylinder));
	if (!(parse_length(token_array[4], &cylinder->obj_prop.cylinder.height)))
		return (free_and_return(CY_HGHT_FMT_ERR, cylinder));
	if (!(parse_color(token_array[5], &cylinder->color)))
		return (free_and_return(CY_COL_FMT_ERR, cylinder));
	init_normal_and_intersection(cylinder);
	if (!(link = ft_lstnew(cylinder)))
		return (free_and_return(MALLOC_ERR, cylinder));
	ft_lstadd_front(&main->scene.obj_lst, link);
	return (NO_ERROR);
}
