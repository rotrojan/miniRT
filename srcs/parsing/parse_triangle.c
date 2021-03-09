/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:31:02 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/08 22:53:37 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		parse_triangle(char **token_array, t_main *main)
{
	t_object	*triangle;

	if (!token_array[1] || !token_array[2] || !token_array[3] || !token_array[4]
		|| token_array[5])
		return (TR_FMT_ERR);
	if (!(triangle = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	triangle->obj_type = TRIANGLE;
	if (!(parse_vector(token_array[1], &triangle->position)))
		return (free_and_return(TR_VER_FMT_ERR, triangle));
	if (!(parse_vector(token_array[2], &triangle->obj_prop.triangle.vertice2)))
		return (free_and_return(TR_VER_FMT_ERR, triangle));
	if (!(parse_vector(token_array[3], &triangle->obj_prop.triangle.vertice3)))
		return (free_and_return(TR_VER_FMT_ERR, triangle));
	if (!(parse_color(token_array[4], &triangle->color)))
		return (free_and_return(TR_COL_FMT_ERR, triangle));
	triangle->intersection = &triangle_intersection;
	triangle->get_normal = &triangle_normal;
	ft_lstadd_front(&main->scene.obj_lst, ft_lstnew(triangle));
	return (NO_ERROR);
}
