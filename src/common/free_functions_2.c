/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:48:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 20:12:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_functions.h"

void	free_cmd(t_cmd **pcmd)
{
	t_cmd	*cmd;

	if (!pcmd || !*pcmd)
		return ;
	cmd = *pcmd;
	free_strs(&cmd->argv);
	free(cmd);
	*pcmd = NULL;
}

void	free_cmds(t_cmd ***pcmds)
{
	size_t	cmd_i;
	t_cmd	**cmds;

	if (!pcmds || !*pcmds)
		return ;
	cmds = *pcmds;
	cmd_i = 0;
	while (cmds[cmd_i])
		free_cmd(&cmds[cmd_i++]);
	free(cmds);
	*pcmds = NULL;
}

void	free_prompt(char ***ptokens, t_cmd ***pcmds, char **pline)
{
	free_strs(ptokens);
	free_cmds(pcmds);
	free_str(pline);
}
