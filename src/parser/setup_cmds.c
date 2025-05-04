/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:38:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 22:06:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	_next_cmd(t_cmd **cmds, size_t *cmd_i, size_t *arg_i, char *token)
{
	cmds[*cmd_i]->argv[*arg_i] = NULL;
	cmds[*cmd_i]->argc = *arg_i;
	(*arg_i) = 0;
	(*cmd_i)++;
	set_cmd_type(cmds[*cmd_i], token);
}

t_cmd	**setup_cmds(t_cmd **cmds, char **tokens)
{
	size_t	token_i;
	size_t	cmd_i;
	size_t	arg_i;

	token_i = 0;
	cmd_i = 0;
	arg_i = 0;
	set_cmd_type(cmds[0], tokens[token_i]);
	while (tokens[token_i])
	{
		if (is_separator(tokens[token_i]))
			_next_cmd(cmds, &cmd_i, &arg_i, tokens[token_i]);
		else
		{
			ft_strlcpy(cmds[cmd_i]->argv[arg_i], tokens[token_i],
				ft_strlen(tokens[token_i]) + 1);
			if (!cmds[cmd_i]->argv[arg_i])
				return (free_cmds(&cmds), NULL);
			arg_i++;
		}
		token_i++;
	}
	cmds[cmd_i]->argc = arg_i;
	return (cmds);
}
