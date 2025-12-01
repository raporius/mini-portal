/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:41:30 by macolomi          #+#    #+#             */
/*   Updated: 2025/12/01 13:25:32 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_celen.h"

static int	numerical_check(t_cmds *cmds)
{
	int	i;

	i = 0;
	if (ft_atol(cmds->argv[1]) > INT_MAX || ft_atoi(cmds->argv[1]) < INT_MIN)
		return (0);
	while (cmds->argv[1][i])
	{
		if (!ft_isdigit(cmds->argv[1][i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_cmds *cmds)
{
	printf("exit\n");
	if (len_tab(cmds->argv) == 1)
		exit(0);
	if (numerical_check(cmds))
	{
		printf("miniportal: exit: %s:"
			" numeric argument required\n", cmds->argv[1]);
		exit(2);
	}
	if (len_tab(cmds->argv) > 2)
	{
		printf("miniportal: exit: too many arguments\n");
		return (1);
	}
	exit((unsigned char)ft_atoi(cmds->argv[1]));
}
