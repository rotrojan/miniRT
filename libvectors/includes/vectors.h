/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:17:21 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/03 17:32:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include <math.h>

typedef float		t_vector __attribute__((ext_vector_type(3)));

float				dot_vectors(t_vector vec1, t_vector vec2);
float				norm_square_vector(t_vector vec);
float				norm_vector(t_vector vec);
t_vector			normalized_vector(t_vector vec);
t_vector			get_vector(float x, float y, float z);

#endif
