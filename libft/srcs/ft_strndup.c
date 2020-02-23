/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:14:49 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/22 20:47:55 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strndup(const char *s1, size_t n)
{
	char			*str;
	size_t			maxlen;

	if (!s1)
		return (NULL);
	maxlen = ft_strnlen(s1, n);
	if (!(str = (char*)malloc(sizeof(*str) * (maxlen + 1))))
		return (NULL);
	*(str + maxlen) = '\0';
	return (ft_memcpy(str, s1, maxlen));
}
