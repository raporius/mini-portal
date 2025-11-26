/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:33:34 by rdestruh          #+#    #+#             */
/*   Updated: 2025/10/20 09:18:01 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_err_return(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	res;
	long	old;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		old = res;
		res = res * 10 + nptr[i] - '0';
		if (res < old)
			return (ft_err_return(sign));
		i++;
	}
	return (res * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*a = "-16546541654651654655";
// 	printf("ref=%d|mine=%d\n", atoi(a), ft_atoi(a));
// 	return (0);
// }
