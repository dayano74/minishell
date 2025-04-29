/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:14:15 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 12:51:12 by dayano           ###   ########.fr       */
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

/**
 * @brief 	old execute_cmd function
 * 			execvp(cmd->argv[0], cmd->argv);
			fprintf(stderr, "%s: command not found: %s\n", program_name,
			cmd->argv[0]);
 * @brief
 * @param cmd_head
 * @param minish
 */
void	exec_pipeline(t_cmd *cmd_head, t_minish *minish)
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
		if (!is_tail(cmd))
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
			cmd = cmd->next;
			continue ;
		}
		if (!is_head(cmd, cmd_head))
		{
			dup2(fds1[0], STDIN_FILENO);
			close(fds1[0]);
			close(fds1[1]);
		}
		if (!is_tail(cmd))
		{
			close(fds2[0]);
			dup2(fds2[1], STDOUT_FILENO);
			close(fds2[1]);
		}
		if ((cmd->next != NULL) && is_redirect(cmd->next))
		{
			redirect(cmd->next);
		}
		if (is_builtin(cmd))
		{
			exec_unit_builtin(cmd);
			exit(EXIT_SUCCESS);
		}
		execute_cmd(cmd, minish);
		cmd->status = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Wait for one command’s process to finish.
 *
 * This function calls waitpid() for cmd->pid, stores the exit
 * or signal status into cmd->status, and returns that status.
 *
 * @param cmd  The command whose child process to wait for.
 * @return     The exit status or 128+signal number on signal,
	or EXIT_FAILURE on error.
 */
static int	_get_status(t_cmd *cmd)
{
	int	ret;
	int	status;

	ret = 0;
	ret = waitpid(cmd->pid, &status, 0);
	if (ret < 0)
	{
		cmd->status = EXIT_FAILURE;
		return (cmd->status);
	}
	if (WIFEXITED(status))
		cmd->status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		cmd->status = 128 + WTERMSIG(status);
	else
		cmd->status = EXIT_FAILURE;
	return (cmd->status);
}

/**
 * @brief Wait for all child processes in the pipeline to finish.
 *
 * This function walks through each command in the pipeline,
 * calls waitpid() for every non-redirect node, stores each
 * child’s exit or signal status into cmd->status, and then
 * returns the status of the last command executed.
 *
 * @param cmd_head  Pointer to the head of the command list.
 * @return          The exit status of the last command in the pipeline.
 */
int	wait_pipeline(t_cmd *cmd_head)
{
	int		last_status;
	int		ret;
	t_cmd	*cmd;

	last_status = 0;
	ret = 0;
	cmd = cmd_head;
	while (cmd)
	{
		if (!is_redirect(cmd))
			last_status = _get_status(cmd);
		cmd = cmd->next;
	}
	return (last_status);
}
