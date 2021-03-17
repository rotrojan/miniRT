/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/16 23:21:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			parse_ratio(char *ratio_str, double *ratio)
{
	parse_length(ratio_str, ratio);
	if (*ratio < 0.0 || *ratio > 1.0)
		return (FALSE);
	return (TRUE);
}
