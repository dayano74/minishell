/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:14:15 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 21:26:01 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	initialize_fds(int fds1[2], int fds2[2])
{
	fds1[0] = -1;
	fds1[1] = -1;
	fds2[0] = -1;
	fds2[1] = -1;
}

bool	is_redirect(t_cmd *cmd)
{
	if (cmd->type != REDIR_NONE)
		return (true);
	return (false);
}

static void	exec_pipeline(t_cmd *cmd_head, t_minish *minish)
{
	t_cmd	*cmd;
	int		fds1[2];
	int		fds2[2];

	cmd = cmd_head;
	initialize_fds(fds1, fds2);
	while (cmd && !is_redirect(cmd))
	{
		fds1[0] = fds2[0];
		fds1[1] = fds2[1];
		if (!TAIL_P(cmd))
		{
			if (pipe(fds2) < 0)
			{
				perror("pipe");
				exit(3);
			}
		}
		cmd->pid = fork();
		if (cmd->pid < 0)
		{
			perror("fork");
			exit(3);
		}
		if (cmd->pid > 0)
		{
			if (fds1[0] != -1)
				close(fds1[0]);
			if (fds1[1] != -1)
				close(fds1[1]);
			continue ;
		}
		if (!HEAD_P(cmd))
		{
			close(STDIN_FILENO);
			dup2(fds1[0], STDIN_FILENO);
			close(fds1[0]);
			close(fds1[1]);
		}
		if (!TAIL_P(cmd))
		{
			close(fds2[0]);
			close(STDOUT_FILENO);
			dup2(fds2[1], STDOUT_FILENO);
			close(fds2[1]);
		}
		if ((cmd->next != NULL) && REDIRECT_P(cmd->next))
		{
			redirect_stdout(cmd->next->argv[0]);
		}
		if (!BUILTIN_P(cmd))
		{
			execute_cmd(cmd, minish);
			// execvp(cmd->argv[0], cmd->argv);
			// fprintf(stderr, "%s: command not found: %s\n", program_name,
			// 	cmd->argv[0]);
			exit(EXIT_FAILURE);
		}
		cmd = cmd->next;
	}
}

static int	wait_pipeline(t_cmd *cmd_head)
{
	(void)cmd_head;
	return (0);
}
