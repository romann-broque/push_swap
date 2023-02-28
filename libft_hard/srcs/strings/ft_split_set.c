/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:29:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/01/04 16:47:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, const char *charset)
{
	size_t	count;
	bool	is_word;

	count = 0;
	is_word = false;
	while (*s != '\0')
	{
		if (ft_strchr(charset, *s) != NULL)
		{
			if (is_word == true)
			{
				++count;
				is_word = false;
			}
		}
		else
			is_word = true;
		++s;
	}
	return (count + (is_word == true));
}

static size_t	get_wordlen(const char *s, const char *charset)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen] != '\0' && ft_strchr(charset, s[wordlen]) == NULL)
		++wordlen;
	return (wordlen);
}

static char	*get_word(const char **s, const char *charset)
{
	size_t	wordlen;
	char	*word;

	while (ft_strchr(charset, **s) != NULL)
		++(*s);
	wordlen = get_wordlen(*s, charset);
	word = (char *)malloc((wordlen + 1) * sizeof(char));
	if (word != NULL)
		ft_strlcpy(word, *s, wordlen + 1);
	*s += wordlen;
	return (word);
}

char	**ft_split_set(char const *s, const char *charset)
{
	size_t	nbof_words;
	size_t	i;
	char	**split;

	if (s == NULL)
		return (NULL);
	nbof_words = count_words(s, charset);
	split = (char **)malloc((nbof_words + 1) * sizeof(char *));
	if (split != NULL)
	{
		i = 0;
		split[nbof_words] = NULL;
		while (i < nbof_words)
		{
			split[i] = get_word(&s, charset);
			if (split[i] == NULL)
			{
				free_strs(split);
				split = NULL;
				break ;
			}
			++i;
		}
	}
	return (split);
}
