/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:13:57 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/01 14:31:15 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error				parse_light(char **token_array, t_scene *scene)
{
	t_object	*light;

	if (!token_array[1] || !token_array[2] || !token_array[3] || token_array[4])
		return (LIGHT_ERR);
	if (!(light = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	if (!(parse_vector(token_array[1], &light->position)))
	{
		free(light);
		return (LIGHT_POS_ERR);
	}
	if (!(parse_ratio(token_array[2], &light->obj_prop.light.intensity)))
	{
		free(light);
		return (LIGHT_INTENS_ERR);
	}
	if (!(parse_color(token_array[3], &light->color)))
	{
		free(light);
		return (LIGHT_INTENS_ERR);
	}
	ft_lstadd_front(&scene->light_lst, ft_lstnew(light));
	return (NO_ERROR);
}
