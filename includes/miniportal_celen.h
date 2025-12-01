/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniportal_celen.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:20:32 by celen             #+#    #+#             */
/*   Updated: 2025/12/01 14:19:06 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPORTAL_CELEN_H
# define MINIPORTAL_CELEN_H

# include "libft.h"
# include "portal.h"
# include "structs.h"

void	ft_killprog(t_cmds **cmds);
void	big_big_free(char **to_free);

//builtins

int		ft_pwd(void);
int		ft_exit(t_cmds *cmds);
int		ft_echo(t_cmds *cmds);

//utils

int		len_tab(char **argv);

#endif
