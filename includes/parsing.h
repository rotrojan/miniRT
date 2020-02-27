/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/27 17:48:51 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minirt.h"

t_error			parser(int fd, t_list **obj_lst);

/*
** parsing_utils{1,2,3}.c
*/

t_error		parse_resolution(char **token_array, t_list **obj_lst);
t_error		parse_ambient(char **token_array, t_list **obj_lst);
t_error		parse_camera(char **token_array, t_list **obj_lst);
t_error		parse_light(char **token_array, t_list **obj_lst);
t_error		parse_sphere(char **token_array, t_list **obj_lst);
t_error		parse_plane(char **token_array, t_list **obj_lst);
t_error		parse_square(char **token_array, t_list **obj_lst);
t_error		parse_cylinder(char **token_array, t_list **obj_lst);
t_error		parse_triangle(char **token_array, t_list **obj_lst);
t_bool		parse_vector(char *point_str, t_vector *point);
t_bool		parse_color(char *color_str, t_color *color);
t_bool		parse_length(char *length_str, double *length);
t_bool		parse_ratio(char *ratio_str, double *ratio);
t_bool		parse_orientation(char *orientation_str, t_vector *orientation_vec);

#endif
