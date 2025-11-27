/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celen <celen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:23:17 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/27 14:53:27 by celen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_power_int(int nb, int power)
{
	long	result;
	long	temp_nb;

	result = 1;
	temp_nb = nb;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		if (temp_nb != 0 && \
			(result > INT_MAX / temp_nb || result < INT_MIN / temp_nb))
			return (INT_MAX);
		result *= temp_nb;
		power--;
	}
	return ((int)result);
}

long	ft_power_long(long nb, int power)
{
	long long	result;
	long long	temp_nb;

	result = 1;
	temp_nb = nb;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		if (temp_nb != 0 \
			&& (result > LONG_MAX / temp_nb || result < LONG_MIN / temp_nb))
			return (LONG_MAX);
		result *= temp_nb;
		power--;
	}
	return ((long)result);
}
