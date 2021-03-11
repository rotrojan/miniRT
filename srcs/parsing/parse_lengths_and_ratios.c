/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lengths_and_ratios.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/10 23:30:16 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			parse_length(char *length_str, double *length)
{
	char	*tmp;

	tmp = length_str;
	if (*tmp == '+' || *tmp == '-')
		++tmp;
	if (!ft_isdigit(*tmp))
		return (FALSE);
	while (ft_isdigit(*tmp))
		++tmp;
	if (*tmp == '.')
		++tmp;
	if (ft_isdigit(*tmp))
		while (ft_isdigit(*tmp))
			++tmp;
	if (*tmp)
		return (FALSE);
	*length = ft_atod(length_str);
	if (*length < 0)
		return (FALSE);
	return (TRUE);
}

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
