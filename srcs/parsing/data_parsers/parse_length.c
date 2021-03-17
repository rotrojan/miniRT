/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 10:16:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			parse_length(char *length_str, double *length)
{
	char	*tmp;

	tmp = length_str;
	if (!(check_double(&tmp)))
		return (FALSE);
	if (*tmp)
		return (FALSE);
	*length = ft_atod(length_str);
	if (*length < 0)
		return (FALSE);
	return (TRUE);
}
