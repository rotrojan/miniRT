/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:05:30 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/23 17:32:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//static void print_sphere (t_list)

t_bool	parse_sphere(char **token_array, t_list **parsed_objects_list)
{
	t_object	*object;
	int			i;

	i = 0;
	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (return_error("Malloc failure.", parsed_objects_list));
	object->object_id = SPHERE;
	if (!(parse_vector(token_array[1], &object->object_type.sphere.center)))
		return (return_error("Sphere position not well formatted.", parsed_objects_list));
	if (!(parse_length(token_array[2], &object->object_type.sphere.radius)))
		return (return_error("Sphere radius not well formatted.", parsed_objects_list));
	if (!(parse_color(token_array[3], &object->object_type.sphere.color)))
		return (return_error("Sphere color not well formatted.", parsed_objects_list));
	if (token_array[4])
		return (return_error("Sphere informations not well formatted.", parsed_objects_list));
	ft_lstadd_back(parsed_objects_list, ft_lstnew(&object));
	return (TRUE);
}

t_bool	parse_plane(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}

t_bool	parse_square(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}

t_bool	parse_cylinder(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}

t_bool	parse_triangle(char **token_array, t_list **parsed_objects_list)
{
	(void)token_array;
	(void)parsed_objects_list;
	return (TRUE);
}
