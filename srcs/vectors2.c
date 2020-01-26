/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:11:48 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/24 00:20:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		norm_square_vector(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double		norm_vector(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}
