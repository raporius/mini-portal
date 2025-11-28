/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_struct_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:23:39 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/28 14:24:41 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

t_envp	*envnode_new(char *name, char *val)
{
	t_envp	*new;

	new = malloc(sizeof(t_envp));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->val = val;
	new->next = NULL;
	return (new);
}

void	envnode_add(t_envp **envp, t_envp *new)
{
	t_envp	*current;

	current = *envp;
	if (current == NULL)
	{
		*envp = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

void	envnode_remove_by_name(t_envp **envp, char *to_remove)
{
	t_envp	*current;
	t_envp	*prev;

	current = *envp;
	prev = NULL;
	while (current)
	{
		if (!ft_strncmp(current->name, to_remove, ft_strlen(to_remove) + 1))
		{
			free(current->name);
			free(current->val);
			if (prev)
			{
				if (current->next)
					prev->next = current->next;
				else
					prev->next = NULL;
			}
			else
				*envp = current->next;
			free(current);
		}
		prev = current;
		current = current->next;
	}
}

void	envp_clean(t_envp **envp)
{
	t_envp	*current;

	while (*envp)
	{
		free((*envp)->name);
		free((*envp)->val);
		current = *envp;
		(*envp) = (*envp)->next;
		free(current);
	}
}
