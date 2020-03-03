/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 08:42:14 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minirt.h"

typedef struct	s_nb_elem
{
	int			nb_lights;
	int			nb_cameras;
	int			nb_objects;
}				t_nb_elem;

/*
** parser.c
*/

t_error			open_and_parse_file(int ac, char **av, t_scene *scene,
																	t_mlx *mlx);

/*
** parse_utils.c
*/

t_error			check_args(int ac, char **av);
t_type			get_sub_parser(char *first_token);
t_error			select_sub_parser(t_type type, char **token_array,
													t_scene *scene, t_mlx *mlx);

/*
** parse_data.c
*/

t_bool			parse_vector(char *point_str, t_vector *point);
t_bool			parse_color(char *color_str, t_color *color);
t_bool			parse_length(char *length_str, double *length);
t_bool			parse_ratio(char *ratio_str, double *ratio);
t_bool			parse_orientation(char *orientation_str,
													t_vector *orientation_vec);

/*
** parse_resolution.c
*/

t_error			parse_resolution(char **token_array, t_mlx *mlx);

/*
** parse_ambient.c
*/

t_error			parse_ambient(char **token_array, t_scene *scene);

/*
** parse_camera.c
*/

t_error			parse_camera(char **token_array, t_scene *scene);

/*
** parse_light.c
*/

t_error			parse_light(char **token_array, t_scene *scene);

/*
** parse_sphere.c
*/

t_error			parse_sphere(char **token_array, t_scene *scene);

/*
** parse_plane.c
*/

t_error			parse_plane(char **token_array, t_scene *scene);

/*
** parse_square.c
*/

t_error			parse_square(char **token_array, t_scene *scene);

/*
** parse_cylinder.c
*/

t_error			parse_cylinder(char **token_array, t_scene *scene);

/*
** parse_triangle.c
*/

t_error			parse_triangle(char **token_array, t_scene *scene);

#endif
