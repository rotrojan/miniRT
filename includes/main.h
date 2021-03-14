/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 05:56:14 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 12:21:02 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "minirt.h"

/*
** The main data-structure where the scene and the mlx data are stored.
*/

typedef struct	s_main
{
	t_mlx		mlx;
	t_scene		scene;
}				t_main;

#endif
