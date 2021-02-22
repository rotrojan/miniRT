/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 05:56:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/17 14:21:36 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "minirt.h"

typedef struct	s_main
{
	t_mlx		mlx;
	t_scene		scene;
	t_bool		(*intersection[9])(t_ray*, t_object*, double*);
	// t_vector	(*get_normal[9])(t_object, t_vector);
}				t_main;

#endif
