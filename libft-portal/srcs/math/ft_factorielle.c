/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorielle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:07:00 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/21 18:13:00 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_int_factorielle(int nb)
{
	long	nbr;

	if (nb < 0)
		return (0);
	nbr = 1;
	while (nb > 1)
	{
		if (nbr > INT_MAX / nb)
			return (INT_MAX);
		nbr *= nb;
		nb--;
	}
	return ((int)nbr);
}

long	ft_long_factorielle(long nb)
{
	long long	nbr;

	if (nb < 0)
		return (0);
	nbr = 1;
	while (nb > 1)
	{
		if (nbr > INT_MAX / nb)
			return (INT_MAX);
		nbr *= nb;
		nb--;
	}
	return ((long)nbr);
}
