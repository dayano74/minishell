/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:48:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 19:48:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_functions.h"

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
