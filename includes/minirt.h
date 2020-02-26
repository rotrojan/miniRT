/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 03:51:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "libft/includes/libft.h"
# include "libvectors/includes/vectors.h"
# include "mlx_defines.h"
# include "mlx_utils.h"
# include "objects.h"
# include "libmlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <fcntl.h>
# define TITLE "minirt"

typedef enum	e_error
{
	NO_ERROR,
	NB_ARGS_ERR,
	OPENING_ERR,
	FILE_EXTENSION_ERR,
	THIRD_ARG_ERR,
	READ_ERR,
	MALLOC_ERR,
	WRONG_ELEM_ERR,
	SP_POS_FMT_ERR,
	SP_COL_FMT_ERR,
	SP_LEN_FMT_ERR,
	SP_FMT_ERR,
	RES_X_FMT_ERR,
	RES_Y_FMT_ERR,
	RES_TWICE_ERR,
	RES_FMT_ERR,
	AMB_FMT_ERR,
	AMB_RATIO_ERR,
	AMB_COL_ERR
}				t_error;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_ray
{
	t_vector		direction;
	t_vector		origin;
}				t_ray;

/*
** colors_and_geometrics.c
*/

double			length_vector(t_vector vec);
t_vector		vectorize(t_vector a, t_vector b);

/*
** ray_tracer.c
*/

int				ray_tracer(t_mlx *mlx);

/*
** parsing_utils{1,2,3}.c
*/

t_error			parse_resolution(char **token_array, t_list **obj_lst);
t_error			parse_ambient(char **token_array, t_list **obj_lst);
t_error			parse_camera(char **token_array, t_list **obj_lst);
t_error			parse_light(char **token_array, t_list **obj_lst);
t_error			parse_sphere(char **token_array, t_list **obj_lst);
t_error			parse_plane(char **token_array, t_list **obj_lst);
t_error			parse_square(char **token_array, t_list **obj_lst);
t_error			parse_cylinder(char **token_array, t_list **obj_lst);
t_error			parse_triangle(char **token_array, t_list **obj_lst);
t_bool			parse_vector(char *point_str, t_vector *point);
t_bool			parse_color(char *color_str, t_color *color);
t_bool			parse_length(char *length_str, double *length);
t_bool			parse_ratio(char *ratio_str, double *ratio);

/*
** utils.c
*/

t_error			check_args(int ac, char **av);
t_error			parser(int fd, t_list **obj_lst);
t_error			return_error(t_error num_error, t_list **obj_lst);
void			free_array(void **array);
void			del(void *content);

#endif
