/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/01 13:32:29 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "vectors.h"
# include "ray.h"
# include "bool.h"
# include "objects.h"
# include "mlx_utils.h"
# include "mlx_defines.h"
# include "main.h"
# include "mlx_hooks.h"
# include "errors.h"
# include "parsing.h"
# define TITLE "miniRT"
# define WIN_X_MAX 2560
# define WIN_Y_MAX 1395

typedef struct	s_quadratic
{
	double a;
	double b;
	double c;
	double x0;
	double x1;
}				t_quadratic;

/*
** ray_tracer.c
*/

t_error	ray_tracer(t_main *main);

/*
** intersection.c
*/

t_bool	plane_intersection(t_ray ray, t_object plane, double *t);
t_bool	sphere_intersection(t_ray ray, t_object sphere, double *t);
t_bool	square_intersection(t_ray ray, t_object square, double *t);
t_bool	cylinder_intersection(t_ray ray, t_object cylinder, double *t);
t_bool	triangle_intersection(t_ray ray, t_object triangle, double *t);

/*
** normal.c
*/

 t_vector	sphere_normal(t_object sphere, t_vector point);
 t_vector	plane_normal(t_object plane, t_vector point);
 t_vector	square_normal(t_object square, t_vector point);
 t_vector	cylinder_normal(t_object cylinder, t_vector point);
 t_vector	triangle_normal(t_object triangle, t_vector point);

/*
** utils.c
*/

t_error	return_error(t_error num_error);
void	free_array(void **array);
void	del(void *content);
void	free_scene(t_scene *scene);
t_color	get_color(double r, double g, double b);
t_color	shade_color(double coef, t_color color);
t_color	add_colors(t_color color1, t_color color2);

/*
** screenshot.c
*/

t_error	screen_shot(t_main *main);
#endif
