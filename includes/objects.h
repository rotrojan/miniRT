/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:58:44 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/01 14:30:08 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "minirt.h"

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef enum		e_type
{
	TYPE_ERROR = -1,
	RESOLUTION,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}					t_type;

typedef struct		s_resolution
{
	int				width;
	int				height;
}					t_resolution;

typedef struct		s_ambient
{
	double			ratio;
	t_color			color;
}					t_ambient;

typedef struct		s_camera
{
	t_vector		orientation;
	double			fov;
	t_matrix		cam_to_world;
}					t_camera;

typedef struct		s_light
{
	double			intensity;
}					t_light;

typedef struct		s_sphere
{
	double			radius;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		normal;
}					t_plane;

typedef struct		s_square
{
	t_vector		position;
}					t_square;

typedef struct		s_cylinder
{
	t_vector		position;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		position;
}					t_triangle;

typedef union		u_prop
{
	t_resolution	resolution;
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_sphere		sphere;
	t_plane			plane;
	t_square		square;
	t_cylinder		cylinder;
	t_triangle		triangle;
}					t_prop;

typedef struct		s_object
{
	t_type			obj_type;
	t_prop			obj_prop;
	t_vector		position;
	t_color			color;
	t_bool			(*intersection)(t_ray, struct s_object, double*);
	t_vector		(*get_normal)(struct s_object, t_vector);
}					t_object;

typedef struct		s_scene
{
	t_ambient		ambient;
	t_list			*cam_lst;
	t_list			*light_lst;
	t_list			*obj_lst;
}					t_scene;

#endif
