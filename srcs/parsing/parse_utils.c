/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 07:07:14 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 08:37:28 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	while (*elem_type_array[++type])
		if (!(ft_strcmp(first_token, elem_type_array[type])))
			return (type);
	return (TYPE_ERROR);
}

t_error		select_sub_parser(t_type type, char **token_array, t_scene *scene,
																	t_mlx *mlx)
{
	static t_error		(*sub_parser[])(char**, t_scene*) = {
		NULL,
		&parse_ambient,
		&parse_camera,
		&parse_light,
		&parse_sphere,
		&parse_plane,
		&parse_square,
		&parse_cylinder,
		&parse_triangle
	};

	if (type == RESOLUTION)
		return (parse_resolution(token_array, mlx));
	return (sub_parser[type](token_array, scene));
}
