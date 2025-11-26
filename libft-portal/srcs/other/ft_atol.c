/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:24:16 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/26 12:42:53 by macolomi         ###   ########.fr       */
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
	if (nbr > INT_MAX || nbr < 0)
		return (LONG_MAX);
	if (negative)
		nbr = nbr * -1;
	return (nbr);
}

int	ft_atol_p(const char *str, long *nbr)
{
	size_t		i;
	bool		negative;

	negative = 0;
	*nbr = 0;
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
		*nbr = *nbr * 10 + (str[i] - '0');
		i++;
	}
	if (negative)
		*nbr = *nbr * -1;
	return (i);
}
