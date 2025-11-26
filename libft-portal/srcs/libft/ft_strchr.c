/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:10:18 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 10:14:18 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*haystack;

// 	haystack = "haystack";
// 	printf("%d\n", strchr(haystack, 'a') == ft_strchr(haystack, 'a'));
// 	printf("%d\n", strchr(haystack, '\0') == ft_strchr(haystack, '\0'));
// 	printf("%d\n", strchr(haystack, 'h') == ft_strchr(haystack, 'h'));
// 	printf("%d\n", strchr(haystack, 'k') == ft_strchr(haystack, 'k'));
// 	printf("%d\n", strchr(haystack, 'g') == ft_strchr(haystack, 'g'));
// 	printf("%d\n", strchr(haystack, 't') == ft_strchr(haystack, 't'));
// 	return (0);
// }
