/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 15:44:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/X.h>
# include <X11/keysymdef.h>
# include "mlx.h"
# include "libft.h"
# include "vectors.h"
# include "bool.h"
# include "objects.h"
# include "mlx_struct.h"
# include "main.h"
# include "mlx_functions.h"
# include "errors.h"
# include "parsing.h"
# define TITLE "miniRT"

/*
** Contains all the coefficients needed to solve polynomial equations.
*/

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

void			ray_tracer(t_main *main);
t_object		*get_closest_intersection(t_ray ray, t_main *main, double *t);

/*
** shader.c
*/

t_color			shader(t_ray current_ray, t_object closest_obj,
								t_vector closest_intersection, t_main *main);

/*
** All the ray-shape intersection functions.
*/

t_bool			plane_intersection(t_ray ray, t_object plane, double *t);
t_bool			sphere_intersection(t_ray ray, t_object sphere, double *t);
t_bool			square_intersection(t_ray ray, t_object square, double *t);
t_bool			cylinder_intersection(t_ray ray, t_object cylinder, double *t);
t_bool			triangle_intersection(t_ray ray, t_object triangle, double *t);

/*
** solve_quadratic.c
*/

t_bool			solve_quadratic(t_quadratic *quad);

/*
** normal.c
*/

t_vector		sphere_normal(t_object sphere, t_vector point);
t_vector		plane_normal(t_object plane, t_vector point);
t_vector		square_normal(t_object square, t_vector point);
t_vector		cylinder_normal(t_object cylinder, t_vector point);
t_vector		triangle_normal(t_object triangle, t_vector point);

/*
** utils.c
*/

t_error			return_error(t_error num_error);
void			free_scene(t_scene *scene, int is_after_parsing);
t_color			get_color(double r, double g, double b);
t_color			shade_color(double coef, t_color color);
t_color			add_colors(t_color color1, t_color color2);
t_color			mix_colors(t_color color1, t_color color2);

/*
** screenshot.c
*/

t_error			screen_shot(t_main *main);

#endif
