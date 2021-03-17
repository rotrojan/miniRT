/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:13:57 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 01:55:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error				parse_light(char **token_array, t_main *main)
{
	t_object	*light;
	t_list		*link;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (LIGHT_ERR);
	if (!(light = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	if (!(parse_vector(token_array[1], &light->position)))
		return (free_and_return(LIGHT_POS_ERR, light));
	if (!(parse_ratio(token_array[2], &light->obj_prop.light.intensity)))
		return (free_and_return(LIGHT_INTENS_ERR, light));
	if (!(parse_color(token_array[3], &light->color)))
		return (free_and_return(LIGHT_COL_ERR, light));
	if (!(link = ft_lstnew(light)))
		return (free_and_return(MALLOC_ERR, light));
	ft_lstadd_front(&main->scene.light_lst, link);
	return (NO_ERROR);
}
