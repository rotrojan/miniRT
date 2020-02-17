/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:07:45 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/16 23:17:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(char const *str)
{
	double		int_part;
	double		dec_part;
	char		is_negative;
	int			len_dec_part;

	while (ft_isspace(*str))
		str++;
	is_negative = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	int_part = 0;
	while (ft_isdigit(*str))
		int_part = int_part * 10.0f + (float)(*(str++) - '0');
	if (*str == '.')
		str++;
	len_dec_part = 0;
	dec_part = 0;
	while (ft_isdigit(*str))
	{
		dec_part = dec_part * 10.0f + (float)(*(str++) - '0');
		len_dec_part++;
	}
	while (len_dec_part--)
		dec_part /= 10.0f;
	return ((int_part + dec_part) * is_negative);
}
