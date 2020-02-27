/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:33:48 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/27 17:16:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_type	get_token(char *first_token)
{
	t_type				type;
	static char const	*elem_type_array[10] = {"R", "A", "c", "l", "sp", "pl",
		"sq", "cy", "tr", NULL};

	type = 0;
	while (*elem_type_array[type])
	{
		if (!(ft_strcmp(first_token, elem_type_array[type])))
			return (type);
		type++;
	}
	return (TYPE_ERROR);
}

t_error		select_sub_parser(t_type type, char **token_array, t_list **obj_lst)
{
	static t_error		(*sub_parser[])(char**, t_list**) = {
		&parse_resolution,
		&parse_ambient,
		&parse_camera,
		&parse_light,
		&parse_sphere,
		&parse_plane,
		&parse_square,
		&parse_cylinder,
		&parse_triangle
	};

	return (sub_parser[type](token_array, obj_lst));
}

t_error	free_line_and_return_error(char **current_line, t_error num_error)
{
	free(*current_line);
	current_line = NULL;
	return (num_error);
}

t_error	parse_line(char ***token_array, char **current_line, t_list **obj_lst)
{
	t_type		token;

	if (!*current_line)
	{
		free(*current_line);
		current_line = NULL;
		return (NO_ERROR);
	}
	if (!(*token_array = ft_split_whitespaces(*current_line)))
		return (MALLOC_ERR);
	if ((token = get_token(*token_array[0])) == TYPE_ERROR)
		return (WRONG_ELEM_ERR);
	select_sub_parser(token, *token_array, obj_lst);
	free_array((void*)*token_array);
	free(*current_line);
	return (NO_ERROR);
}

t_error	parser(int fd, t_list **obj_lst, t_nb_elem *to_malloc)
{
	int			ret_gnl;
	t_error		error;
	char		*current_line;
	char		**token_array;

	current_line = NULL;
	ft_bzero(to_malloc, sizeof(*to_malloc));
	while ((ret_gnl = get_next_line(fd, &current_line)) > 0)
	{
		if ((error = parse_line(&token_array, &current_line, obj_lst))
			!= NO_ERROR)
			return (free_line_and_return_error(&current_line, error));
		if (*((t_object*)obj_lst->content)obj_type == CAMERA)
			to_malloc.nb_cameras++;
		else if (*((t_object*)obj_lst->content)obj_type == LIGHT)
			to_malloc.nb_lights++;
		else if ((*((t_object*)obj_lst->content)obj_type != RESOLUTION)
			&& (*((t_object*)obj_lst->content)obj_type != AMBIENT)
			to_malloc.nb_objects++;
	}
	if (ret_gnl == -1)
		return (free_line_and_return_error(&current_line, READ_ERR));
	free(current_line);
	return (NO_ERROR);
}
