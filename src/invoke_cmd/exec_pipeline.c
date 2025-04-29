/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:14:15 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 16:36:09 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_fds(int fds[2])
{
	fds[0] = -1;
	fds[1] = -1;
}

void	cleanup_fds(int fds1[2])
{
	if (fds1[0] != -1)
		close(fds1[0]);
	if (fds1[1] != -1)
		close(fds1[1]);
}

void	swap_fds(int prev_fds[2], int curr_fds[2])
{
	prev_fds[0] = curr_fds[0];
	prev_fds[1] = curr_fds[1];
}

void	create_pipe(bool need, int fds[2], t_cmd *cmd)
{
	if (!need)
	{
		fds[0] = -1;
		fds[1] = -1;
		return ;
	}
	if (pipe(fds) < 0)
	{
		print_error(cmd->argv[0]);
		exit(EX_OSERR);
	}
}

void	setup_stdin(t_cmd *cmd, t_cmd *cmd_head, int prev_fds[2])
{
	if (is_head(cmd, cmd_head) || prev_fds[0] < 0)
		return ;
	if (dup2(prev_fds[0], STDIN_FILENO) < 0)
	{
		print_error(cmd->argv[0]);
		exit(EX_OSERR);
	}
	close(prev_fds[0]);
	close(prev_fds[1]);
}

void	setup_stdout(t_cmd *cmd, int curr_fds[2])
{
	if (!is_tail(cmd) || curr_fds[1] >= 0)
	{
		close(curr_fds[0]);
		if (dup2(curr_fds[1], STDOUT_FILENO) < 0)
		{
			print_error(cmd->argv[0]);
			exit(EX_OSERR);
		}
		close(curr_fds[1]);
	}
}

pid_t	fork_command(t_cmd *cmd, t_cmd *cmd_head, t_pipe_io *pipefds,
		t_minish *minish)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		print_error(cmd->argv[0]);
		exit(EX_OSERR);
	}
	if (pid > 0)
		return (pid);
	setup_stdin(cmd, cmd_head, pipefds->prev_fds);
	setup_stdout(cmd, pipefds->curr_fds);
	if ((cmd->next != NULL) && is_redirect(cmd->next))
		redirect(cmd->next);
	if (is_builtin(cmd))
		exit(exec_unit_builtin(cmd));
	execute_cmd(cmd, minish);
	print_error(cmd->argv[0]);
	exit(EXIT_FAILURE);
}

/**
 * @brief
 *
 * @param cmd_head
 * @param minish
 */
void	exec_pipeline(t_cmd *cmd_head, t_minish *minish)
{
	t_cmd		*cmd;
	t_pipe_io	pipefds;
	bool		need_pipe;

	cmd = cmd_head;
	init_fds(pipefds.prev_fds);
	init_fds(pipefds.curr_fds);
	while (cmd && !is_redirect(cmd))
	{
		need_pipe = !is_tail(cmd);
		create_pipe(need_pipe, pipefds.curr_fds, cmd);
		cmd->pid = fork_command(cmd, cmd_head, &pipefds, minish);
		cleanup_fds(pipefds.prev_fds);
		swap_fds(pipefds.prev_fds, pipefds.curr_fds);
		init_fds(pipefds.curr_fds);
		cmd = cmd->next;
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
