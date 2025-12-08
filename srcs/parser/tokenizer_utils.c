/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:56:57 by rdestruh          #+#    #+#             */
/*   Updated: 2025/12/08 15:17:31 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"

void	manage_quote_flags(char c, int flags[3])
{
	if (c == '\'')
		flags[1] = 1;
	else if (c == '"')
		flags[2] = 1;
}

void	loop_start(int flags[3], int *i, int *token_len, char const *s)
{
	*token_len = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (s[*i] && s[*i] == ' ')
		(*i)++;
}

int	is_operator(char c, char prev, int mode)
{
	if (mode)
	{
		if (prev == c && prev != '|')
			return (1);
	}
	else
	{
		if (c == '<' || c == '>' || c == '|')
			return (1);
	}
	return (0);
}
