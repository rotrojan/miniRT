/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:17:21 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/10 22:52:25 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	sub_vectors(t_vector vec1, t_vector vec2)
{
	return (get_vector(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z));
}
