/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:44:32 by rdestruh          #+#    #+#             */
/*   Updated: 2025/12/01 15:54:51 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

void	replace_key(char *data[2], t_envp *key)
{
	free(data[0]);
	if (data[1])
	{
		free(key->val);
		key->val = data[1];
	}
}

int	create_insert_key(char *data[2], t_envp *env)
{
	t_envp	*new;

	new = envnode_new(data[0], data[1]);
	if (!new)
	{
		free(data[0]);
		free(data[1]);
		return (0);
	}
	else
		envnode_add(&env, new);
	return (1);
}