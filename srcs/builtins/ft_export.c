/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:08:46 by rdestruh          #+#    #+#             */
/*   Updated: 2025/12/01 15:47:58 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

static void	default_mode(t_envp *env)
{
	while (env)
	{
		printf("export ");
		printf("%s", env->name);
		if (env->val)
			printf("=\"%s\"", env->val);
		printf("\n");
		env = env->next;
	}
}

static int	parse_export(char *to_conv, char *data[2])
{
	if (!ft_strchr(to_conv, '='))
	{
		data[1] = NULL;
		data[0] = ft_strdup(to_conv);
		if (!data[0])
			return (0);
		return (1);
	}
	data[0] = ft_substr(to_conv, 0, ft_strchr(to_conv, '=') - to_conv);
	if (!data[0])
		return (0);
	data[1] = ft_substr(to_conv,
		ft_strchr(to_conv, '=') - to_conv + 1, ft_strlen(to_conv));
	if (!data[1])
	{
		free(data[0]);
		return (0);
	}
	return (1);
}

static int	ft_print_error(char *err_msg, char *arg)
{
	ft_dprintf(2, err_msg, arg);
	return (1);
}

static int	manage_arg(char *arg, t_envp *env)
{
	char	*data[2];
	t_envp	*key;

	if (!ft_isalpha(arg[0]))
		return (ft_print_error(\
"mini-portal: export: '%s': not a valid identifier\n", arg));
	if (!parse_export(arg, data))
		return (ft_print_error(\
"mini-portal: export: '%s': malloc error\n", arg));
	key = search_key(data[0], env);
	if (key)
		replace_key(data, key);
	else
	{
		if (!create_insert_key(data, env))
			return (ft_print_error(\
"mini-portal: export: '%s': malloc error\n", arg));
	}
	return (0);
}

int	ft_export(t_cmds *cmd)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (len_tab(cmd->argv) == 1)
		default_mode(cmd->envp);
	else
	{
		while (i < len_tab(cmd->argv))
		{
			ret += manage_arg(cmd->argv[i], cmd->envp);
			i++;
		}
	}
	if (ret > 0)
		return (1);
	return (0);
}
