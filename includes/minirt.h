/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/03 18:37:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "mlx.h"
# include "libft.h"
# include "vectors.h"
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <fcntl.h>
# define TITLE "minirt"
# define RED_BYTE 2
# define GREEN_BYTE 1
# define BLUE_BYTE 0

#include <stdio.h>

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

typedef t_vector	t_point;

typedef float t_color __attribute__((ext_vector_type(3)));

typedef struct		s_camera
{
	t_point		position;
	t_vector	direction;
	float		fov;
}					t_camera;

typedef struct		s_light
{
	t_point		position;
	double		intensity;
}					t_light;

typedef struct		s_ray
{
	t_vector	direction;
	t_point		origin;
}					t_ray;

typedef struct		s_sphere
{
	t_point		center;
	double		radius;

}					t_sphere;

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
void				render(t_application *app);
int					close_application(t_application *app);
void				put_pixel
	(t_application *app, int x, int y, t_color color);

/*
** drawings.c
*/

void				draw_rectangle
	(t_application *app, int x, int y, t_vector vec, int color);
void				draw_circle
	(t_application *app, int x, int y, double radius, int color);

/*
** colors_and_geometrics.c
*/

float				length_vector(t_vector vec);
t_vector			vectorize(t_point a, t_point b);

/*
** ray_tracer.c
*/

int					ray_tracer(t_application *app);


/*
** 
*/

#endif
