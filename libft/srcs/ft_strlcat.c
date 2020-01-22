/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:34:45 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/22 03:45:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t		len_dst;
	size_t		len_src;

	len_dst = ft_strnlen(dst, dstsize);
	len_src = ft_strlen(src);
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	if (len_src < dstsize - len_dst)
		ft_memcpy(dst + len_dst, src, len_src + 1);
	else
	{
		ft_memcpy(dst + len_dst, src, dstsize - 1);
		*(dst + dstsize - 1) = '\0';
	}
	return (len_src + len_dst);
}
