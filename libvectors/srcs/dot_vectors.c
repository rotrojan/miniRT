/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:29:07 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/28 12:58:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	dot_vectors(t_vector vec1, t_vector vec2)
{
	return ((double)(vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z));
}
