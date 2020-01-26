/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/24 04:51:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <fcntl.h>
# define TITLE "test"
# define WIN_X 1024
# define WIN_Y 1024
# define RED_BYTE 2
# define GREEN_BYTE 1
# define BLUE_BYTE 0


typedef struct		s_application
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}					t_application;

typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
}					t_vector;

typedef t_vector	t_point;

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
	(t_application *app, int x, int y, int color);

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
** vectors.c
*/

t_vector			add_vectors(t_vector vec1, t_vector vec2);
t_vector			sub_vectors(t_vector vec1, t_vector vec2);
t_vector			mul_vector(t_vector vec, double nb);
t_vector			div_vector(t_vector vec, double nb);
double				dot_vectors(t_vector vec1, t_vector vec2);
double				norm_square_vector(t_vector vec);
double				norm_vector(t_vector vec);

/*
** 
*/

#endif
