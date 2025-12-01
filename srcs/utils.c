/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:42:20 by macolomi          #+#    #+#             */
/*   Updated: 2025/12/01 14:11:51 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_celen.h"

int	len_tab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	ft_killprog(t_cmds **cmds)
{
	t_cmds	*current;
	t_cmds	*next;

	current = (*cmds);
	while (current)
	{
		next = current->next;
		if (current->argv)
			big_big_free(current->argv);
		if (current->envp)
			// ft_killenvp(current->envp);
		if (current->infile)
			free(current->infile);
		if (current->outfile)
			free(current->outfile);
		free(current);
		current = next;
	}
	*cmds = NULL;
}

void	big_big_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
