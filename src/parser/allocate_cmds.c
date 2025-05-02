/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:19:28 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 18:43:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	_allocate_argv(t_cmd *cmd, char **token_ptr)
{
	size_t	arg_i;
	size_t	len;

	cmd->argv = calloc_argv(token_ptr);
	if (!cmd->argv)
		return (1);
	arg_i = 0;
	len = count_args_until_separator(token_ptr);
	while (arg_i < len)
	{
		cmd->argv[arg_i] = calloc_arg(token_ptr[arg_i]);
		if (!cmd->argv[arg_i])
		{
			while (0 < arg_i)
				free(cmd->argv[--arg_i]);
			free(cmd->argv);
			return (1);
		}
		arg_i++;
	}
	return (0);
}

static t_cmd	*_allocate_cmd(char **token_ptr)
{
	t_cmd	*cmd;

	cmd = calloc_cmd();
	if (!cmd)
		return (NULL);
	if (_allocate_argv(cmd, token_ptr))
		return (free(cmd), NULL);
	return (cmd);
}

t_cmd	**allocate_cmds(char **tokens)
{
	char	**token_ptr;
	t_cmd	**cmds;
	size_t	cmd_i;
	size_t	len;

	cmds = calloc_cmds(tokens);
	if (!cmds)
		return (NULL);
	cmd_i = 0;
	len = count_cmds(tokens);
	token_ptr = tokens;
	while (cmd_i < len)
	{
		cmds[cmd_i] = _allocate_cmd(token_ptr);
		if (!cmds[cmd_i])
			return (free_cmds(cmds, cmd_i), NULL);
		if (cmd_i > 0)
			cmds[cmd_i - 1]->next = cmds[cmd_i];
		token_ptr = next_cmd_start(token_ptr);
		cmd_i++;
	}
	return (cmds);
}
