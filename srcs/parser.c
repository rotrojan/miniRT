/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:33:48 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 04:09:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_type		get_token(char *first_token)
{
	t_type				type;
	static char const	*elem_type_array[10] = {
		"R",
		"A",
		"c",
		"l",
		"sp",
		"pl",
		"sq",
		"cy",
		"tr",
		NULL
	};

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

t_error		free_line_and_return_error(char **current_line, t_error num_error)
{
	free(*current_line);
	current_line = NULL;
	return (num_error);
}

t_error		parser(int fd, t_list **obj_lst)
{
	int			ret_gnl;
	char		*current_line;
	char		**token_array;
	t_type		token;

	while ((ret_gnl = get_next_line(fd, &current_line)) > 0)
	{
		if (!*current_line)
		{
			free(current_line);
			current_line = NULL;
			continue ;
		}
		if (!(token_array = ft_split_whitespaces(current_line)))
			return (free_line_and_return_error(&current_line, MALLOC_ERR));
		if ((token = get_token(token_array[0])) == TYPE_ERROR)
			return (free_line_and_return_error(&current_line, WRONG_ELEM_ERR));
		select_sub_parser(token, token_array, obj_lst);
		free_array((void*)token_array);
		free(current_line);
	}
	if (ret_gnl == -1)
		return (free_line_and_return_error(&current_line, READ_ERR));
	free(current_line);
	return (NO_ERROR);
}
