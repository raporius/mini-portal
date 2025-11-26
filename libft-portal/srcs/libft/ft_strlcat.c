/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:45:19 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/16 16:19:48 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	while (i < size && dst[i] != '\0')
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (i + j < size - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char *t = malloc(18);
// 	strcpy(t, "bonjour l");
// 	size_t	o = ft_strlcat(t, "e monde", 5);
// 	printf("%s\n%lu\n", t, o);
// 	free(t);
// 	return (0);
// }
