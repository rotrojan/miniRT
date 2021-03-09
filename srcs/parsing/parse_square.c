/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:28:50 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/08 22:50:14 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		parse_square(char **token_array, t_main *main)
{
	t_object	*square;

	if (!token_array[1] || !token_array[2] || !token_array[3] || !token_array[4]
		|| token_array[5])
		return (SQ_FMT_ERR);
	if (!(square = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	square->obj_type = SQUARE;
	if (!(parse_vector(token_array[1], &square->position)))
		return (free_and_return(SQ_POS_FMT_ERR, square));
	if (!(parse_orientation(token_array[2], &square->obj_prop.square.normal)))
		return (free_and_return(SQ_ORIENT_FMT_ERR, square));
	if (!(parse_length(token_array[3], &square->obj_prop.square.size)))
		return (free_and_return(SQ_LEN_FMT_ERR, square));
	if (!(parse_color(token_array[4], &square->color)))
		return (free_and_return(SQ_COL_FMT_ERR, square));
	square->intersection = &square_intersection;
	square->get_normal = &square_normal;
	ft_lstadd_front(&main->scene.obj_lst, ft_lstnew(square));
	return (NO_ERROR);
}
