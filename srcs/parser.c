/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:33:48 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/22 23:40:48 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			get_token(char *first_token)
{
	int				i;
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

	i = 0;
	while (*elem_type_array[i])
	{
		if (!(ft_strcmp(first_token, elem_type_array[i])))
			return (i);
		i++;
	}
	return (-1);
}

t_bool		select_sub_parser
	(t_token elem_type, char **token_array, t_list **parsed_objects_list)
{
	static t_bool	(*sub_parser[9])(char**, t_list**) = {
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

	if (!(sub_parser[elem_type](token_array, parsed_objects_list)))
		return (FALSE);
	return (TRUE);
}

t_bool		parser(char *rt_file, t_list **parsed_objects_list)
{
	int			fd;
	int			ret_gnl;
	char		*current_line;
	char		**token_array;
	int			elem_type;

	if ((fd = open(rt_file, O_RDONLY)) == -1)
		return (return_error("Cannot open file.", parsed_objects_list));
	while ((ret_gnl = get_next_line(fd, &current_line)))
	{
		if (ret_gnl == -1)
			return (return_error("Cannot read file.", parsed_objects_list));
		if (!*current_line)
			continue ;
		if (!(token_array = ft_split_whitespaces(current_line)))
			return (return_error("Malloc failure.", parsed_objects_list));
		if ((elem_type = get_token(*token_array)) == -1)
			return (return_error("Invalid element in file.", parsed_objects_list));
		if (!select_sub_parser(elem_type, token_array, parsed_objects_list))
			return (FALSE);
		free(current_line);
		current_line = NULL;
		free_array((void*)token_array);
		token_array = NULL;
	}
	printf("yolo\n");
	close(fd);
	return (TRUE);
}
