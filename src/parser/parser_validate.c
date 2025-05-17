/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:03:42 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/17 16:02:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	_error(char *arg)
{
	ft_putstr_fd("minish: syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

static bool	_check_pipe(t_cmd *cmd, t_cmd ***cmds_ptr, t_minish *minish)
{
	if (cmd->type == REDIR_NONE && cmd->argc == 0)
	{
		_error("|");
		minish->last_status = 2;
		free_cmds(cmds_ptr);
		return (false);
	}
	return (true);
}

static bool	_check_redir(t_cmd *cmd, t_cmd ***cmds_ptr, t_minish *minish)
{
	if (cmd->type != REDIR_NONE && cmd->argc == 0)
	{
		_error("newline");
		minish->last_status = 2;
		free_cmds(cmds_ptr);
		return (false);
	}
	return (true);
}

bool	parser_validate(t_cmd ***cmds_ptr, t_minish *minish)
{
	t_cmd	*cmd;
	t_cmd	**cmds;

	if (!cmds_ptr || !*cmds_ptr)
		return (true);
	cmds = *cmds_ptr;
	cmd = *cmds;
	while (cmd)
	{
		if (!_check_pipe(cmd, cmds_ptr, minish)
			|| !_check_redir(cmd, cmds_ptr, minish))
			return (false);
		cmd = cmd->next;
	}
	return (true);
}
