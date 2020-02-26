/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:58:44 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/25 22:17:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "minirt.h"

typedef t_vector	t_color;

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
	t_vector		position;
	t_vector		direction;
	double			fov;
}					t_camera;

typedef struct		s_light
{
	t_vector		position;
	double			intensity;
}					t_light;

typedef struct		s_sphere
{
	t_vector		center;
	double			radius;
	t_color			color;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		positionn;
}					t_plane;

typedef struct		s_square
{
	t_vector		positionn;
}					t_square;

typedef struct		s_cylinder
{
	t_vector		positionn;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		positionn;
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
}					t_object;

#endif
