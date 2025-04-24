/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:29 by dayano            #+#    #+#             */
/*   Updated: 2025/04/24 14:57:00 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redirect_stdout(t_cmd *cmd)
{
	(void)cmd;
}

bool	is_redirect(t_cmd *cmd)
{
	if (cmd->type != REDIR_NONE)
		return (true);
	return (false);
}

bool	is_head(t_cmd *cmd)
{
	(void)cmd;
	return (true);
}

bool	is_tail(t_cmd *cmd)
{
	(void)cmd;
	return (true);
}

bool	is_builtin(t_cmd *cmd)
{
	(void)cmd;
	return (true);
}
