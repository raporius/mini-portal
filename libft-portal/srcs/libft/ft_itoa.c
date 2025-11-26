/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:33:30 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/16 16:53:21 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_itoa(long nb, size_t index, char *result)
{
	if (nb / 10 != 0)
		ft_rec_itoa(nb / 10, index - 1, result);
	result[index] = nb % 10 + '0';
}

static size_t	ft_get_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*result;
	long	nb;

	nb = n;
	size = ft_get_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	ft_rec_itoa(nb, size - 1, result);
	return (result);
}
