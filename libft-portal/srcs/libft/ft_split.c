/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:59 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:16 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		word_count++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (word_count);
}

static void	big_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	**ft_split_main(char const *s, char c,
	char **res, size_t word_count)
{
	size_t	current_word;
	size_t	i;
	size_t	len;

	current_word = 0;
	i = 0;
	len = 0;
	while (current_word < word_count)
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		res[current_word] = ft_substr(s, i, len);
		if (res[current_word] == NULL)
		{
			big_free(res);
			return (NULL);
		}
		current_word++;
		i += len;
	}
	res[word_count] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**result;

	if (s == NULL)
		return (NULL);
	word_count = ft_count_word(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	return (ft_split_main(s, c, result, word_count));
}
