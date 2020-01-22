/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:46:11 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/22 03:54:17 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			count_words(char const *s, char c)
{
	size_t		nb_words;

	nb_words = 0;
	if (*s != c)
		nb_words++;
	while (*(s++))
		if (*s != c && *(s - 1) == c)
			nb_words++;
	return (nb_words);
}

static void				*malloc_failure(char ***current_word, char **first_word)
{
	while (**(current_word--) >= *first_word)
		free(**current_word);
	free(*current_word);
	return (NULL);
}

char					**ft_split(char const *s, char c)
{
	char	**current_word;
	char	**first_word;
	char	*begin_word;

	if (!s || !(current_word = (char**)malloc(sizeof(*current_word)
		* (count_words(s, c) + 1))))
		return (NULL);
	first_word = current_word;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		begin_word = (char*)s;
		while (*s && *s != c)
			s++;
		if (!(*current_word = ft_strndup(begin_word, s - begin_word)))
			return (malloc_failure(&current_word, first_word));
		while (*s && *s == c)
			s++;
		current_word++;
	}
	*current_word = NULL;
	return (first_word);
}
