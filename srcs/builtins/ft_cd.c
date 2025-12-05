/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macolomi <macolomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:41:29 by macolomi          #+#    #+#             */
/*   Updated: 2025/12/05 16:33:54 by macolomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_celen.h"

static char	*get_pwd(void)
{
	char	*buffer;
	size_t	size;

	size = 16;
	buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	while (!getcwd(buffer, size))
	{
		free (buffer);
		size += 16;
		buffer = malloc(size + 1);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

static char	*cd_parsing(t_cmds *cmds)
{
	char	*pwd;
	char	*path;

	if (!ft_strncmp(cmds->argv[1][0], "/", 1))
	{
		pwd = get_pwd();
		path = ft_strjoin(pwd, cmds->argv[1]);
		if (!path)
		{
			ft_dprintf(2, "Malloc Error\n");
			return (NULL);
		}
		free (pwd);
		return (path);
	}
	else
		return (cmds->argv[1]);
}

static int	*access_parsing(char *path, t_cmds *cmds)
{
	if (access(path, F_OK))
	{
		ft_dprintf(2, "Minishell: cd: %s: No such file or directory\n", \
			cmds->argv[1]);
		free (path);
		return (1);
	}
	if (access(path, R_OK))
	{
		ft_dprintf(2, "Minishell: cd: %s: Permission denied\n", \
			cmds->argv[1]);
		free (path);
		return (1);
	}
	return (0);
}

static void	edit_pwds(t_cmds *cmds)
{
	t_envp	*old_pwd;
	t_envp	*new_pwd;

	old_pwd = search_key("OLDPWD", cmds->envp);
	new_pwd = search_key("PWD", cmds->envp);
	if (old_pwd)
	{
		free(old_pwd->val);
		if (new_pwd)
		{
			old_pwd->val = new_pwd->val;
			new_pwd->val = NULL;
		}
		else
			old_pwd->val = NULL;
	}
	if (new_pwd)
		new_pwd->val = get_pwd();
	while (!new_pwd->val)
		new_pwd->val = get_pwd();
}

int	ft_cd(t_cmds *cmds)
{
	char		*path;
	struct stat	path_stat;

	if (cmds->argv[1] == NULL)
		return (1);
	path = cd_parsing(cmds);
	if (!path)
		return (1);
	if (access_parsing(path, cmds))
		return (1);
	stat(path, &path_stat);
	if ((!(path_stat.st_mode) & 0170000) == (0040000))
	{
		ft_dprintf(2, "Minishell: cd: %s: Not a directory\n", cmds->argv[1]);
		free(path);
		return (1);
	}
	if (!chdir(path))
	{
		ft_dprintf(2, "Minishell: cd: %s: Chdir crashed\n", cmds->argv[1]);
		free(path);
		return (1);
	}
	edit_pwds(cmds);
	return (0);
}
