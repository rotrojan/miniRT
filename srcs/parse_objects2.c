/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:07:01 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/23 17:32:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_resolution(char **token_array, t_list **parsed_objects_list)
{
	t_list		*current_link;
	t_object	*object;
	char		*tmp;

	current_link = *parsed_objects_list;
	while (current_link)
	{
		if (((t_object*)(current_link->content))->object_id == RESOLUTION)
			return (return_error("Resolution can only be set once.", parsed_objects_list));
			current_link = current_link->next;
	}
	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (return_error("Malloc failure.", parsed_objects_list));
	object->object_id = RESOLUTION;
	tmp = token_array[1];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (return_error("Resolution's width not well formatted.", parsed_objects_list));
	object->object_type.resolution.width = ft_atoi(token_array[1]);
	tmp = token_array[2];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (return_error("Resolution's height not well formatted.", parsed_objects_list));
	object->object_type.resolution.height = ft_atoi(token_array[2]);
	ft_lstadd_back(parsed_objects_list, ft_lstnew(&object));
	return (TRUE);
}

t_bool	parse_ambient(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}

t_bool	parse_camera(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}

t_bool	parse_light(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}
