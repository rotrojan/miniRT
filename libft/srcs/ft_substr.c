/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:54:21 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/22 20:50:08 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else
		len = ft_strnlen(s + start, len);
	if (!(str = ft_strndup(s + start, len)))
		return (NULL);
	return (str);
}
