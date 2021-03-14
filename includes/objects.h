/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:58:44 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 23:26:18 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "minirt.h"

/*
** Self explanatory.
*/

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

/*
** All possible types of elements are tagged in this enum. Its are all stored in
** t_scene structure (except for the resolution stored in the t_mlx structure).
*/

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

/*
** The properties of all elements.
*/

typedef struct		s_ray
{
	t_vector		direction;
	t_vector		origin;
}					t_ray;

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

/*
** Each camera stores its own cam_to_world matrix in order to facilitate cameras
** translations and orientations.
*/

typedef struct		s_camera
{
	t_vector		orientation;
	double			fov;
	t_matrix		cam_to_world;
}					t_camera;

/*
** The description of all possibles ojects.
*/

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
	t_vector		normal;
	double			size;
}					t_square;

typedef struct		s_cylinder
{
	t_vector		orientation;
	double			diameter;
	double			height;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		vertice2;
	t_vector		vertice3;
}					t_triangle;

/*
** This union makes all possibles types of objects condensed in one single
** format : a tagged union.
*/

typedef union		u_prop
{
	t_camera		camera;
	t_light			light;
	t_sphere		sphere;
	t_plane			plane;
	t_square		square;
	t_cylinder		cylinder;
	t_triangle		triangle;
}					t_prop;

/*
** An object is defined as follow : the tag of the object (a t_type enum) which
** allow to know how the union will be read ; the properties (a t_prop union)
** of the object which we can read properly thanks to the tag ; a color and a
** position ; an intersection "method" wixh will be used during the raytracing ;
** a normal method with return the normal of the object at a certain point.
*/

typedef struct		s_object
{
	t_type			obj_type;
	t_prop			obj_prop;
	t_vector		position;
	t_color			color;
	t_bool			(*intersection)(struct s_ray, struct s_object, double*);
	t_vector		(*get_normal)(struct s_object, struct s_vector);
}					t_object;

/*
** A scene is defined by an ambient lighting, a circular chain-linked of
** cameras, a chain-linked list of lights and a chain linked_list of shapes or
** objects.
*/

typedef struct		s_scene
{
	t_ambient		ambient;
	t_list			*cam_lst;
	t_list			*light_lst;
	t_list			*obj_lst;
}					t_scene;

#endif
