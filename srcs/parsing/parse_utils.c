/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 07:07:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 12:19:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The number of arguments, the format of the name of the scene description
** (must end with ".rt") and finally the third argument (must be "-save" or
** "--save") are checked.
*/

t_error		check_args(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		return (NB_ARGS_ERR);
	if (ft_strcmp(".rt", av[1] + ft_strlen(av[1]) - 3))
		return (FILE_EXTENSION_ERR);
	if (av[2])
		if (ft_strcmp(av[2], "--save") && ft_strcmp(av[2], "-save"))
			return (THIRD_ARG_ERR);
	return (NO_ERROR);
}

/*
** Check the first token of each line to recognize the appropriate sub-parser.
*/

t_type		get_sub_parser(char *first_token)
{
	t_type				type;
	static char const	*elem_type_array[] = {
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

	type = -1;
	while (elem_type_array[++type])
		if (!(ft_strcmp(first_token, elem_type_array[type])))
			return (type);
	return (TYPE_ERROR);
}

/*
** Return the function pointer corresponding to the proper sub-parser.
*/

t_error		select_sub_parser(t_type type, char **token_array, t_main *main)
{
	static t_error		(*sub_parser[])(char**, t_main*) = {
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

	return (sub_parser[type](token_array, main));
}

/*
** Self explanatory.
*/

t_error		free_and_return(t_error error, t_object *object)
{
	free(object);
	object = NULL;
	return (error);
}

/*
** Self explanatory.
*/

void		free_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		++i;
	}
	free(array);
	array = NULL;
}
