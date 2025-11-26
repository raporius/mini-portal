/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:24:16 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/26 14:44:23 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

long	ft_atol(const char *str)
{
	size_t		i;
	long		nbr;
	bool		negative;

	negative = 0;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (negative)
		nbr = nbr * -1;
	return (nbr);
}
