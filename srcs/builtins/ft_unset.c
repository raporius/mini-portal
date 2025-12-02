/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:20:42 by rdestruh          #+#    #+#             */
/*   Updated: 2025/12/01 16:25:02 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

int	ft_unset(t_cmds *cmd)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (cmd->argv[i])
	{
		if (!search_key(cmd->argv[i], cmd->envp))
			ret = 1;
		envnode_remove_by_name(&cmd->envp, cmd->argv[i]);
		i++;
	}
	return (ret);
}
