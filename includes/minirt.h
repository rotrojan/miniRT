/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/20 22:45:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# define TITLE "test"
# define WIN_X 1200
# define WIN_Y 900
# define RED_BYTE 2
# define GREEN_BYTE 1
# define BLUE_BYTE 0

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_application
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}				t_application;

typedef struct	s_vector
{
	int		x;
	int		y;
}				t_vector;

/*
** mlx_hooks.c
*/

int				set_mlx_hooks(t_application *app);

/*
** mlx_utils.c
*/

void			init_app(t_application *app);
int				run_application(t_application *app);
void			apply_background(t_application *app, int color);
void			render(t_application *app);
int				close_application(t_application *app);
void			put_pixel
	(t_application *app, t_point pixel_coord, int color);

/*
** drawings.c
*/

void			draw_rectangle
	(t_application *app, t_point top_left_corner, t_vector vec, int color);
void			draw_circle
	(t_application *app, t_point center, t_vector radius, int color);

/*
** colors_and_geometrics.c
*/

float			length_vector(t_vector vec);
t_vector		vectorize(t_point a, t_point b);

#endif
