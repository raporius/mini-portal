/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:07:27 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/21 17:59:36 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_int_abs(int nb)
{
	if (nb == INT_MIN)
		return (INT_MAX);
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

long	ft_long_abs(long nb)
{
	if (nb == LONG_MIN)
		return (LONG_MAX);
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
