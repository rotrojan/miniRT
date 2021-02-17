/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:17:21 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/16 14:53:02 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	scale_vector(double coef, t_vector vec)
{
	return (get_vector(vec.x * coef, vec.y * coef, vec.z * coef));
}
