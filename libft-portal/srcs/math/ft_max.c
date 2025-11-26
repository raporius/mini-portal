/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:38:58 by macolomi          #+#    #+#             */
/*   Updated: 2025/11/21 17:42:15 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	max_int(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

long	max_long(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}
