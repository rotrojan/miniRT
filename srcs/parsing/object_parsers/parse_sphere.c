/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:07:04 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/07 19:15:02 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		parse_sphere(char **token_array, t_main *main)
{
	t_object	*sphere;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (SP_FMT_ERR);
	if (!(sphere = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	sphere->obj_type = SPHERE;
	if (!(parse_vector(token_array[1], &sphere->position)))
		return (free_and_return(SP_POS_FMT_ERR, sphere));
	if (!(parse_length(token_array[2], &sphere->obj_prop.sphere.radius)))
		return (free_and_return(SP_LEN_FMT_ERR, sphere));
	if (!(parse_color(token_array[3], &sphere->color)))
		return (free_and_return(SP_COL_FMT_ERR, sphere));
	sphere->intersection = &sphere_intersection;
	sphere->get_normal = &sphere_normal;
	ft_lstadd_front(&main->scene.obj_lst, ft_lstnew(sphere));
	return (NO_ERROR);
}
