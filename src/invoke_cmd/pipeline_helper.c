/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:29 by dayano            #+#    #+#             */
/*   Updated: 2025/05/01 16:20:19 by dayano           ###   ########.fr       */
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

static bool	str_in_list(char *cmd, char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (!ft_strcmp(cmd, list[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_builtin(t_cmd *cmd)
{
	static char	*builtin_list[] = {"echo", "pwd", "exit", "cd", "env", "export",
			"unset", NULL};

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (false);
	return (str_in_list(cmd->argv[0], builtin_list));
}
