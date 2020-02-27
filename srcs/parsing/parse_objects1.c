/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 03:59:58 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		parse_sphere(char **token_array, t_list **obj_lst)
{
	t_object	*sphere;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (SP_FMT_ERR);
	if (!(sphere = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	sphere->obj_type = SPHERE;
	if (!(parse_vector(token_array[1], &sphere->obj_prop.sphere.center)))
	{
		free(sphere);
		return (SP_POS_FMT_ERR);
	}
	if (!(parse_length(token_array[2], &sphere->obj_prop.sphere.radius)))
	{
		free(sphere);
		return (SP_LEN_FMT_ERR);
	}
	if (!(parse_color(token_array[3], &sphere->obj_prop.sphere.color)))
	{
		free(sphere);
		return (SP_COL_FMT_ERR);
	}
	ft_lstadd_front(obj_lst, ft_lstnew(sphere));
	return (NO_ERROR);
}

t_error		parse_plane(char **token_array, t_list **obj_lst)
{
	(void)token_array;
	(void)obj_lst;
	return (NO_ERROR);
}

t_error		parse_square(char **token_array, t_list **obj_lst)
{
	(void)token_array;
	(void)obj_lst;
	return (NO_ERROR);
}

t_error		parse_cylinder(char **token_array, t_list **obj_lst)
{
	(void)token_array;
	(void)obj_lst;
	return (NO_ERROR);
}

t_error		parse_triangle(char **token_array, t_list **obj_lst)
{
	(void)token_array;
	(void)obj_lst;
	return (NO_ERROR);
}
