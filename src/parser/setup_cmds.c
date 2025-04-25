/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:38:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/25 18:20:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	_allocate_argv(t_cmd *cmd, char **tokens)
{
	size_t	token_i;
	size_t	argc;

	token_i = 0;
	argc = 0;
	while (tokens[token_i] && !is_separator(tokens[token_i]))
	{
		token_i++;
		argc++;
	}
	cmd->argv = ft_calloc(argc + 1, sizeof(char *));
	if (!cmd->argv)
		return (1);
	return (0);
}

static void	_set_type(t_cmd *cmd, char *token)
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

static void	_next_cmd(t_cmd **cmds, size_t *cmd_i, size_t *arg_i, char *token)
{
	cmds[*cmd_i]->argv[*arg_i] = NULL;
	cmds[*cmd_i]->argc = *arg_i;
	(*arg_i) = 0;
	(*cmd_i)++;
	_set_type(cmds[*cmd_i], token);
	_allocate_argv(cmds[*cmd_i], &token);
}

t_cmd	**setup_cmds(t_cmd **cmds, char **tokens)
{
	size_t	token_i;
	size_t	cmd_i;
	size_t	arg_i;

	token_i = 0;
	cmd_i = 0;
	arg_i = 0;
	_set_type(cmds[0], tokens[token_i]);
	_allocate_argv(cmds[0], tokens);
	while (tokens[token_i])
	{
		if (is_separator(tokens[token_i]))
			_next_cmd(cmds, &cmd_i, &arg_i, tokens[token_i]);
		else
		{
			cmds[cmd_i]->argv[arg_i] = ft_strdup(tokens[token_i]);
			if (!cmds[cmd_i]->argv[arg_i])
				return (free_cmds(cmds, cmds_len(cmds)), NULL);
			arg_i++;
		}
		token_i++;
	}
	cmds[cmd_i]->argc = arg_i;
	cmds[++cmd_i] = NULL;
	return (cmds);
}
