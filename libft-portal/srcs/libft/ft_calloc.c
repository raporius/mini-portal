/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:49:48 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/17 15:16:02 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > ((size_t) - 1) / size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*test1;
// 	char	*test2;

// 	test1 = ft_calloc(20, sizeof(char));
// 	test2 = calloc(20, sizeof(char));
// 	printf("%d\n", memcmp(test1, test2, 20));
// 	free(test1);
// 	free(test2);
// 	test1 = ft_calloc(4294967296, 4294967297);
// 	test2 = calloc(4294967296, 4294967297);
// 	printf("%d\n", test1 == test2);
// 	free(test1);
// 	free(test2);
// }
