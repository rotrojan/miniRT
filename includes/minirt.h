/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/17 01:49:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "mlx.h"
# include "libft.h"
# include "vectors.h"
# include "objects.h"
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
# define RED_BYTE 2
# define GREEN_BYTE 1
# define BLUE_BYTE 0

typedef enum		e_token
{
	RESOLUTION,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}					t_token;

typedef struct		s_application
{
	int		win_width;
	int		win_height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}					t_application;

typedef struct		s_ray
{
	t_vector	direction;
	t_vector		origin;
}					t_ray;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

/*
** mlx_hooks.c
*/

int					set_mlx_hooks(t_application *app);

/*
** mlx_utils.c
*/

void				init_app(t_application *app);
int					run_application(t_application *app);
void				apply_background(t_application *app, int color);
int					close_application(t_application *app);
void				put_pixel
	(t_application *app, int x, int y, t_color color);

/*
** colors_and_geometrics.c
*/

double				length_vector(t_vector vec);
t_vector			vectorize(t_vector a, t_vector b);

/*
** ray_tracer.c
*/

int					ray_tracer(t_application *app);

/*
** parsing_utils{1,2,3}.c
*/

void	parse_resolution(char **token_array, t_application *app);
void	parse_ambient(char **token_array, t_object **parsed_object_list);
void	parse_camera(char **token_array, t_object *app);
void	parse_light(char **token_array, t_object **scene);

/*
** 
*/

t_bool				check_args(int ac, char **av);
t_bool
	parser(char *rt_file, t_application *app, t_object **parsed_objects_list);
t_bool				return_error(char *error_message);

#endif
