/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:07:45 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/07 04:15:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(char const *str)
{
	float		result;
	char		is_negative;
	double		divider;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	is_negative = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9' && *str)
		result = result * 10 + *(str++) - '0';
	if (*str == '.')
		str++;
	divider = 10.0f;
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = result + ((*(str++) - '0') / divider);
		divider = divider * 10.0f;
	}
	return (result * is_negative);
}
