/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:05:59 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 10:29:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_int(char **int_str)
{
	if (*(*int_str) == '+' || *(*int_str) == '-')
		++(*int_str);
	if (!ft_isdigit(**int_str))
		return (FALSE);
	while (ft_isdigit(**int_str))
		++(*int_str);
	return (TRUE);
}

t_bool	check_double(char **double_str)
{
	if (!(check_int(double_str)))
		return (FALSE);
	if (**double_str == '.')
	{
		++(*double_str);
		if (!ft_isdigit(*(*double_str)))
			return (FALSE);
		while (ft_isdigit(*(*double_str)))
			++(*double_str);
	}
	return (TRUE);
}
