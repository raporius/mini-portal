/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:43:27 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:41 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	len_calc(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && is_inset(s1[start], set))
		start++;
	if (start == end)
		return (0);
	while (is_inset(s1[end - 1], set))
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			last_len;
	unsigned int	start;
	char			*res;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	last_len = len_calc(s1, set);
	if (s1[0] == '\0' || last_len == 0)
		return (ft_strdup(""));
	if (set[0] == '\0')
	{
		res = ft_strdup(s1);
		if (res == NULL)
			return (NULL);
		return (res);
	}
	while (is_inset(s1[start], set))
		start++;
	res = ft_substr(s1, start, last_len);
	if (res == NULL)
		return (NULL);
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test = ft_strtrim("xhaystackx", "x");
// 	printf("%s\n", test);
// 	free(test);
// 	return (0);
// }
