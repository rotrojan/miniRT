/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 13:59:42 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			parse_ratio(char *ratio_str, double *ratio)
{
	char	*tmp;

	tmp = ratio_str;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp == '.')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (FALSE);
	*ratio = ft_atod(ratio_str);
	if (*ratio < 0.0 || *ratio > 1.0)
		return (FALSE);
	return (TRUE);
}
