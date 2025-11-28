/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:29:34 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/28 14:30:23 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

static void	clean_null_env(t_envp **to_clean)
{
	envp_clean(to_clean);
	*to_clean = NULL;
	exit(1);
}

static int	parse_env(char *to_conv, char *data[2])
{
	data[0] = ft_substr(to_conv, 0, ft_strchr(to_conv, '=') - to_conv);
	if (!data[0])
		return (0);
	data[1] = ft_substr(to_conv, ft_strchr(to_conv, '=') - to_conv + 1, ft_strlen(to_conv));
	if (!data[1])
	{
		free(data[0]);
		return (0);
	}
	return (1);
}

t_envp	*init_envp(char **envp)
{
	t_envp	*ret;
	t_envp	*new;
	char	*data[2];
	int		i;

	i = 0;
	ret = NULL;
	while (envp[i])
	{
		if (!parse_env(envp[i], data))
			clean_null_env(&ret);
		new = envnode_new(data[0], data[1]);
		if (!new)
		{
			free(data[0]);
			free(data[1]);
			clean_null_env(&ret);
		}
		envnode_add(&ret, new);
		i++;
	}
	return (ret);
}
