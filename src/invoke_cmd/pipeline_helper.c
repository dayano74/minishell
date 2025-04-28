/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:29 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 15:04:51 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redirect_stdout(t_cmd *cmd)
{
	int		fd;
	char	*path;

	path = cmd->argv[0];
	close(STDOUT_FILENO);
	if (cmd->type == REDIR_OUT)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->type == REDIR_APPEND)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minish: ", STDERR_FILENO);
		perror(path);
		return ;
	}
	if (fd != 1)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

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
	return (true);
}
