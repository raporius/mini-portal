/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:56:08 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/16 10:07:22 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			*((unsigned char *)dest + i - 1) = *((unsigned char *)src + i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
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
// 	strcpy(test1 + 5, "testest");
// 	strcpy(test2 + 5, "testest");
// 	ft_memmove(test1 + 1, test1 + 5, strlen("testest"));
// 	memmove(test2 + 1, test2 + 5, strlen("testest"));
// 	printf("%d\n", memcmp(test1, test2, 20));
// 	free(test1);
// 	free(test2);
// 	return (0);
// }
