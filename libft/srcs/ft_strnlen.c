/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:07:48 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/30 18:40:53 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(char const *s, size_t maxlen)
{
	size_t		size;

	size = 0;
	if (!s)
		return (0);
	while (*(s + size) && maxlen--)
		size++;
	return (size);
}
