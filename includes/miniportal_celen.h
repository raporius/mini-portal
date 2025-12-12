/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniportal_celen.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:20:32 by celen             #+#    #+#             */
/*   Updated: 2025/12/12 16:03:34 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPORTAL_CELEN_H
# define MINIPORTAL_CELEN_H

# include "libft.h"
# include "portal.h"
# include "structs.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>

void	ft_killprog(t_cmds **cmds);
void	big_big_free(char **to_free);

//builtins

int		ft_pwd(void);
int		ft_cd(t_cmds *cmds);
int		ft_exit(t_cmds *cmds);
int		ft_echo(t_cmds *cmds);

//utils

int		len_tab(char **argv);
int		pipe_nbr(t_cmds *cmds);
void	wait_pids(int *pid_list, int size);
pid_t	*get_pid_t(t_cmds *cmds);
t_cmds	*get_last_cmds(t_cmds *cmds);

#endif
