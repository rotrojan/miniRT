/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:31:28 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/17 16:57:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			count_words(char const *s)
{
	size_t		nb_words;

	nb_words = 0;
	if (!ft_isspace(*s))
		nb_words++;
	while (*(s++))
		if (!ft_isspace(*s) && ft_isspace(*(s - 1)))
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

char					**ft_split_whitespaces(char const *s)
{
	char	**current_word;
	char	**first_word;
	char	*begin_word;

	if (!s || !(current_word = (char**)malloc(sizeof(*current_word)
		* (count_words(s) + 1))))
		return (NULL);
	first_word = current_word;
	while (*s && ft_isspace(*s))
		s++;
	while (*s)
	{
		begin_word = (char*)s;
		while (*s && !ft_isspace(*s))
			s++;
		if (!(*current_word = ft_strndup(begin_word, s - begin_word)))
			return (malloc_failure(&current_word, first_word));
		while (*s && ft_isspace(*s))
			s++;
		current_word++;
	}
	*current_word = NULL;
	return (first_word);
}
