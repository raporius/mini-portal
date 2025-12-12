/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:48:01 by macolomi          #+#    #+#             */
/*   Updated: 2025/12/12 16:05:31 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_celen.h"

pid_t	*get_pid_t(t_cmds *cmds)
{
	pid_t	*p;

	p = ft_calloc(pipe_nbr(cmds), sizeof(pid_t));
	if (!p)
		return (NULL);
	return (p);
}

t_cmds	*get_last_cmds(t_cmds *cmds)
{
	t_cmds	*tmp;

	tmp = cmds;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	pipe_nbr(t_cmds *cmds)
{
	t_cmds	*tmp;
	int		i;

	i = 0;
	tmp = cmds;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	outfile(t_cmds *cmds)
{
	t_cmds *last;
	int		fd;

	last = get_last_cmds(cmds);
	if (last->outfile == NULL)
		return (1);
	else if (last->outfile_mode == 0)
	{
		fd = open(last->outfile, O_WRONLY | O_TRUNC);
		return (fd);
	}
	else
		fd = open(last->outfile, O_WRONLY | O_APPEND);
	return (fd);
}

void	wait_pids(pid_t *pid_list, int size)
{
	int	i;

	waitpid(pid_list[size - 1], NULL, 0);
	close(0);
	i = 0;
	while (i < size - 1)
	{
		waitpid(pid_list[i], NULL, 0);
		i++;
	}
}
