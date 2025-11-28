/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniportal_rapo.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:39:09 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/28 14:38:26 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPORTAL_RAPO_H
# define MINIPORTAL_RAPO_H

# include "libft.h"
# include "portal.h"
# include "structs.h"

//t_envp funcs
t_envp	*envnode_new(char *name, char *val);
void	envnode_add(t_envp **envp, t_envp *new);
void	envnode_remove_by_name(t_envp **envp, char *to_remove);
void	envp_clean(t_envp **envp);

//envp manipulation
t_envp	*init_envp(char **envp);

//builtins
int	ft_env(t_envp *env);

#endif