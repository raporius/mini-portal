/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:45:19 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/21 17:46:00 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	min_int(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

long	min_long(long a, long b)
{
	if (a <= b)
		return (a);
	return (b);
}
