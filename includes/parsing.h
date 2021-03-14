/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:11 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 22:20:17 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minirt.h"

/*
** parser.c
*/

t_error			open_and_parse_file(int ac, char **av, t_main *main);

/*
** parse_utils.c
*/

t_error			check_args(int ac, char **av);
t_error			free_and_return(t_error error, t_object *object);
void			free_array(void **array);
t_type			get_sub_parser(char *first_token);
t_error			select_sub_parser(t_type type, char **token_array,
																t_main *main);

/*
** Data parsers.
*/

t_bool			parse_color(char *color_str, t_color *color);
t_bool			parse_length(char *length_str, double *length);
t_bool			parse_vector(char *point_str, t_vector *point);
t_bool			parse_ratio(char *ratio_str, double *ratio);
t_bool			parse_orientation(char *orientation_str,
													t_vector *orientation_vec);

/*
** Object parsers.
*/

t_error			parse_resolution(char **token_array, t_main *main);
t_error			parse_ambient(char **token_array, t_main *main);
t_error			parse_camera(char **token_array, t_main *main);
t_error			parse_light(char **token_array, t_main *main);
t_error			parse_sphere(char **token_array, t_main *main);
t_error			parse_plane(char **token_array, t_main *main);
t_error			parse_square(char **token_array, t_main *main);
t_error			parse_cylinder(char **token_array, t_main *main);
t_error			parse_triangle(char **token_array, t_main *main);

#endif
