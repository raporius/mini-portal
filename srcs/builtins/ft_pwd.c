/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celen <celen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:14:57 by celen             #+#    #+#             */
/*   Updated: 2025/11/27 14:52:01 by celen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "miniportal_celen.h"

int	ft_pwd(void)
{
	char	*buffer;
	size_t	size;

	size = 10;
	buffer = malloc(size + 1);
	if (!buffer)
		return (1);
	while (!getcwd(buffer, size))
	{
		free (buffer);
		size += 10;
		buffer = malloc(size + 1);
		if (!buffer)
			return (1);
	}
	ft_printf("%s\n", buffer);
	free (buffer);
	return (0);
}
