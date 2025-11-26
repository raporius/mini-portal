/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:11:18 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:30 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((unsigned char) c == '\0')
		return ((char *)s + i);
	while (i > 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i--;
	}
	if (i == 0 && s[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*haystack;

// 	haystack = "haystack";
// 	printf("%d\n", strrchr(haystack, 'a') == ft_strrchr(haystack, 'a'));
// 	printf("%d\n", strrchr(haystack, '\0') == ft_strrchr(haystack, '\0'));
// 	printf("%d\n", strrchr(haystack, 'h') == ft_strrchr(haystack, 'h'));
// 	printf("%d\n", strrchr(haystack, 'k') == ft_strrchr(haystack, 'k'));
// 	printf("%d\n", strrchr(haystack, 'g') == ft_strrchr(haystack, 'g'));
// 	printf("%d\n", strrchr(haystack, 't') == ft_strrchr(haystack, 't'));
// 	return (0);
// }
