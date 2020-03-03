/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 02:14:36 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/02 02:16:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_S
# define RAY_S
# include "minirt.h"

typedef struct	s_ray
{
	t_vector	direction;
	t_vector	origin;
}				t_ray;

#endif
