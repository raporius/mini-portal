/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:37:26 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/16 10:07:18 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*test1;
// 	char	*test2;

// 	test1 = calloc(20, sizeof(char));
// 	test2= calloc(20, sizeof(char));
// 	strcpy(test1 + 1, "testest");
// 	strcpy(test2 + 1, "testest");
// 	ft_memcpy(test1 + 5, test1 + 1, strlen("testest"));
// 	memcpy(test2 + 5, test2 + 1, strlen("testest"));
// 	printf("%d\n", memcmp(test1, test2, 20));
// 	free(test1);
// 	free(test2);
// 	return (0);
// }
