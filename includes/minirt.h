/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/19 03:44:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <mlx.h>
# include <math.h>
# define TITLE "test"
# define WIN_X 800
# define WIN_Y 600
# define RED_BYTE 2
# define GREEN_BYTE 1
# define BLUE_BYTE 0

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_environment
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}				t_environment;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_vector
{
	int		x;
	int		y;
}				t_vector;

/*
** mlx_utils.c
*/

void			init_env(t_environment *env);
int				run_environment(t_environment *env);
void			apply_background(t_environment *env, t_color background);
void			render(t_environment *env);
void			put_pixel
	(t_environment *env, t_point pixel_coord, t_color pixel_color);

/*
** drawings.c
*/

void			draw_rectangle
	(t_environment *env, t_point top_left_corner, t_vector vec, t_color color);
void			draw_circle
		(t_environment *env, t_point center, t_vector radius, t_color color);

/*
** drawing_and_geometrics.c
*/

t_color			create_color
				(unsigned char red, unsigned char green, unsigned char blue);
float			length_vector(t_vector vec);
t_vector		vectorize(t_point a, t_point b);
#endif
