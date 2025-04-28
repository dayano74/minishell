/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:29 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 21:07:41 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_redirect(t_cmd *cmd)
{
	if (cmd->type != REDIR_NONE)
		return (true);
	return (false);
}

bool	is_head(t_cmd *cmd, t_cmd *cmd_head)
{
	if (cmd == cmd_head)
		return (true);
	return (false);
}

bool	is_tail(t_cmd *cmd)
{
	if (cmd->next == NULL || is_redirect(cmd->next))
		return (true);
	return (false);
}

bool	is_builtin(t_cmd *cmd)
{
	(void)cmd;
	return (false);
}
