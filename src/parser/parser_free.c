/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:55:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 21:28:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_tokens(char **tokens)
{
	size_t	token_i;

	token_i = 0;
	while (tokens && tokens[token_i])
		token_i++;
	while (0 < token_i)
		free(tokens[--token_i]);
	free(tokens);
}

void	free_cmd(t_cmd *cmd)
{
	size_t	arg_i;

	arg_i = 0;
	while (cmd->argv && cmd->argv[arg_i])
		free(cmd->argv[arg_i++]);
	free(cmd->argv);
	free(cmd);
}

void	free_cmds(t_cmd **cmds)
{
	size_t	cmd_i;

	cmd_i = 0;
	while (cmds[cmd_i])
		free_cmd(cmds[cmd_i++]);
	free(cmds);
}
