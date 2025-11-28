/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:35:40 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/28 14:36:24 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

int	ft_env(t_envp *env)
{
	while (env)
	{
		if (env->val)
			printf("%s=%s\n", env->name, env->val);
		env = env->next;
	}
	return (0);
}
