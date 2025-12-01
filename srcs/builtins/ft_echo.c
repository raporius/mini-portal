/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:15:39 by macolomi          #+#    #+#             */
/*   Updated: 2025/12/01 14:18:41 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_celen.h"

static int	check_n(char *str, int *n)
{
	int	i;

	i = 1;
	if (ft_strncmp(str, "-n", 2))
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	*n = 1;
	return (1);
}

int	ft_echo(t_cmds *cmds)
{
	int	n;
	int	i;

	i = 1;
	n = 0;
	while (cmds->argv[i] && check_n(cmds->argv[i], &n))
		i++;
	while (cmds->argv[i])
	{
		printf("%s", cmds->argv[i]);
		if (cmds->argv[i + 1])
			printf(" ");
		i++;
	}
	if (n)
		return (0);
	printf("\n");
	return (0);
}
