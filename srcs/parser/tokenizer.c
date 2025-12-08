/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:36:16 by rdestruh          #+#    #+#             */
/*   Updated: 2025/12/08 15:22:11 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniportal_rapo.h"
#include <readline/readline.h>
#include <readline/history.h>

static int	the_knife(char const *s, int i, int token_len, t_list **tokens)
{
	t_list	*new;
	char	*new_token;

	new_token = ft_substr(s, i, token_len);
	if (!new_token)
		return (1);
	new = ft_lstnew(new_token);
	if (!new)
	{
		free(new_token);
		return (1);
	}
	ft_lstadd_back(tokens, new);
	return (0);
}

static int	knife_precision(char const *s, int i, int *token_len, int flags[3])
{
	if ((flags[1] && s[i + *token_len] == '\'') || (flags[2]
			&& s[i + *token_len] == '"'))
	{
		(*token_len)++;
		return (1);
	}
	else if (flags[0])
	{
		if (is_operator(s[i + *token_len], s[i + *token_len - 1], 1))
			(*token_len)++;
		return (1);
	}
	else if (!flags[1] && !flags[2] && (s[i + *token_len] == '\''
			|| s[i + *token_len] == '"'))
		manage_quote_flags(s[i + *token_len], flags);
	else if (i + *token_len - 1 >= 0 && !flags[1] && !flags[2]
		&& is_operator(s[i + *token_len], s[i + *token_len - 1], 0))
	{
		flags[0] = 1;
		if (*token_len != 0 && s[i + *token_len - 1] != ' ')
			return (1);
	}
	else if (!flags[1] && !flags[2] && s[i + *token_len] == ' ')
		return (1);
	return (0);
}

t_list	*tokenpie_cutter(char const *s)
{
	t_list	*tokens;
	int		i;
	int		token_len;
	int		flags[3];

	i = 0;
	tokens = NULL;
	while (s[i])
	{
		loop_start(flags, &i, &token_len, s);
		while (s[i + token_len])
		{
			if (knife_precision(s, i, &token_len, flags))
				break ;
			token_len++;
		}
		if (the_knife(s, i, token_len, &tokens))
		{
			ft_dprintf(2, "minishell: Error while parsing \
the input, please retry. :(\n");
			return (NULL);
		}
		i += token_len;
	}
	return (tokens);
}
