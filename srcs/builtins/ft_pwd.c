/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:14:57 by celen             #+#    #+#             */
/*   Updated: 2025/11/28 14:13:22 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "miniportal_celen.h"

int	ft_pwd(void)
{
	char	*buffer;
	size_t	size;

	size = 16;
	buffer = malloc(size + 1);
	if (!buffer)
		return (1);
	while (!getcwd(buffer, size))
	{
		free (buffer);
		size += 16;
		buffer = malloc(size + 1);
		if (!buffer)
			return (1);
	}
	printf("%s\n", buffer);
	free (buffer);
	return (0);
}
