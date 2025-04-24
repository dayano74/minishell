/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:38:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/24 14:08:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perser.h"

static void _set_type(t_cmd *cmd, char *token)
{
	if (!ft_strcmp(token, ">"))
		cmd->type = REDIR_OUT;
	else if (!ft_strcmp(token, ">>"))
		cmd->type = REDIR_APPEND;
	else if (!ft_strcmp(token, "<"))
		cmd->type = REDIR_IN;
	else if (!ft_strcmp(token, "<<"))
		cmd->type = REDIR_HEREDOC;
	else
		cmd->type = REDIR_NONE;
	
}

t_cmd **setup_cmds(t_cmd **cmds, char **tokens)
{
	size_t	token_i;
	size_t	cmd_i;
	size_t	arg_i;

	token_i = 0;
	cmd_i = 0;
	arg_i = 0;
	_set_type(cmds[0], tokens[token_i]);
	while (tokens[token_i])
	{
		if (is_separator(tokens[token_i]))
		{
			cmds[cmd_i]->argv[arg_i] = NULL;
			cmds[cmd_i]->argc = arg_i;
			arg_i = 0;
			cmd_i++;
		}
		else
		{
			cmds[cmd_i]->argv[arg_i] = ft_strdup(tokens[token_i]);
			arg_i++;
		}
		token_i++;
	}
	cmds[cmd_i] = NULL;
	return (cmds);
}
