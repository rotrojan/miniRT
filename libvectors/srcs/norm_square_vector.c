/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_square_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:40:38 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/03 18:41:45 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float		norm_square_vector(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
