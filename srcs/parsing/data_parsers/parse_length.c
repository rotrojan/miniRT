/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/16 23:26:03 by rotrojan         ###   ########.fr       */
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
	{
		++tmp;
		if (!ft_isdigit(*tmp))
			return (FALSE);
		while (ft_isdigit(*tmp))
			++tmp;
	}
	if (*tmp)
		return (FALSE);
	*length = ft_atod(length_str);
	if (*length < 0)
		return (FALSE);
	return (TRUE);
}
