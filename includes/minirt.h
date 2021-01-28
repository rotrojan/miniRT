/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/26 14:42:52 by bigo             ###   ########.fr       */
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

/*
** Linux Compatibility
*/

// #define XK_MISCELLANY
// #include <X11/keysymdef.h>
// #include <X11/Xlib.h>

/*
** ray_tracer.c
*/

t_error	ray_tracer(t_main *main);

/*
** intersection.c
*/

t_bool	plane_intersection(t_ray *current, t_object *plane, double *t);
t_bool	sphere_intersection(t_ray *current, t_object *sphere, double *t);
t_bool	square_intersection(t_ray *current, t_object *square, double *t);
t_bool	cylinder_intersection(t_ray *current, t_object *cylinder, double *t);
t_bool	triangle_intersection(t_ray *current, t_object *triangle, double *t);

/*
** utils.c
*/

t_error	return_error(t_error num_error);
void	free_array(void **array);
void	del(void *content);
void	free_scene(t_scene *scene);

/*
** utils.c
*/

t_error	screen_shot(t_main *main);

#endif
