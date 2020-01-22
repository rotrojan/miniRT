/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 02:37:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/10/30 19:05:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t		len_needle;
	size_t		len_haystack;

	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (!haystack || !*haystack || len_needle > len_haystack
		|| ft_strlen(haystack) < len_needle)
		return (NULL);
	if (!needle || !*needle)
		return ((char*)haystack);
	while (--len_haystack && ft_strncmp(haystack, needle, len_needle))
	{
		haystack--;
		if (len_haystack < len_needle)
			return (NULL);
	}
	return ((char*)haystack);
}
