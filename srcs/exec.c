/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:04:43 by macolomi          #+#    #+#             */
/*   Updated: 2025/12/10 16:02:56 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_celen.h"

void	ft_builtins_exec(t_cmds *cmds)
{
	if (!ft_strncmp(cmds->argv[0], "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(cmds->argv[0], "cd", 2))
		ft_cd(cmds);
	else if (!ft_strncmp(cmds->argv[0], "echo", 4))
		ft_echo(cmds);
}

pid_t	piping(t_cmds *cmds, pid_t *p, int	to_close)
{
	pid_t	child_pid;
	int		fd_pipe[2];
	int		i;

	i = 0;
	close(to_close);
	if (pipe(fd_pipe) == -1)
		ft_dprintf(2, "Error while piping\n");
	child_pid = fork();
	if (child_pid == -1)
		ft_dprintf(2, "Error while forking\n");
	if (child_pid == 0)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
		ft_exec(cmds);
	}
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
	}
	return (child_pid);
}

pid_t	last_pipe(t_cmds *cmds, int new_fd)
{
	pid_t	pid;

	if (new_fd != 1)
	{
		dup2(new_fd, 1);
		close(new_fd);
	}
	pid = fork();
	if (pid == -1)
		manage_error("Error while forking", 0);
	if (pid == 0)
		ft_exec(cmds);
	return (pid);
}



void	pipex(t_cmds *cmds)
{
	t_cmds	*current;
	pid_t	*p;
	int		new_fd[2];
	int		i;

	current = cmds;
	i = 0;
	if (!ft_strncmp(cmds->argv[0], "exit", 4))
	{
		ft_exit(cmds);
		return ;
	}
	dup2(new_fd[0], 0);
	close(new_fd[0]);
	new_fd[1] = outfile(cmds);
	if (new_fd[1] == -1)
		ft_dprintf(2, "Error while opening outfile\n");
	p = get_pid_t(cmds);
	while (current->next->next)
	{
		p[i] = piping(cmds, p, new_fd[1]);
		i++;
		current = current->next;
	}
	waitpid
}
