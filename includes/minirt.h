/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:31 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/27 17:50:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "libft/includes/libft.h"
# include "libmlx/mlx.h"
# include "libvectors/includes/vectors.h"
# include "mlx_utils.h"
# include "objects.h"
# include "errors.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <fcntl.h>
# define TITLE "minirt"
# define WIN_X_MAX 2560
# define WIN_Y_MAX 1395

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

# include "parsing.h"

typedef struct	s_nb_elem
{
	int		nb_lights;
	int		nb_cameras;
	int		nb_objects;
}				t_nb_elem;

typedef struct	s_ray
{
	t_vector	direction;
	t_vector	origin;
}				t_ray;

/*
** ray_tracer.c
*/

int				ray_tracer(t_mlx *mlx);

/*
** utils.c
*/

t_error			check_args(int ac, char **av);
t_error			return_error(t_error num_error);
void			free_array(void **array);
void			del(void *content);

#endif
