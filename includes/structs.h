/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:03:15 by rdestruh          #+#    #+#             */
/*   Updated: 2025/12/10 15:11:58 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_envp
{
	char			*name;
	char			*val;
	struct s_envp	*next;
}	t_envp;

typedef struct s_cmds
{
	char			**argv;
	t_envp			*envp;
	char			*infile;
	char			*outfile;
	bool			outfile_mode;
	bool			is_builtin;
	struct s_cmds	*next;
}	t_cmds;

#endif