/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:38:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/18 16:44:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	_copy_token(char **arg_p, char **token_p)
{
	size_t	len;

	if (!arg_p || !token_p || !*arg_p || !*token_p)
		return (false);
	len = ft_strlen(*token_p) + 1;
	return (ft_strlcpy(*arg_p, *token_p, len) < len);
}

t_cmd	*setup_cmd(t_cmd *cmd, char ***tokens_p)
{
	size_t	a_i;
	char	**tokens;

	a_i = 0;
	tokens = *tokens_p;
	if (is_separator(tokens[0]))
	{
		set_cmd_type(cmd, tokens[0]);
		if (tokens[1])
			set_heredoc_flg(cmd, tokens[1]);
		tokens++;
	}
	while (*tokens && !is_separator(*tokens))
	{
		*tokens = trim_quote_token(*tokens);
		if (!_copy_token(&cmd->argv[a_i], tokens))
			return (NULL);
		tokens++;
		a_i++;
	}
	cmd->argc = a_i;
	*tokens_p = tokens;
	return (cmd);
}

t_cmd	**setup_cmds(t_cmd **cmds, char **tokens)
{
	size_t	c_i;

	c_i = 0;
	while (*tokens)
	{
		if (!setup_cmd(cmds[c_i], &tokens))
			return (free_cmds(&cmds), NULL);
		c_i++;
	}
	return (cmds);
}
