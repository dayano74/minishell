/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:14:15 by dayano            #+#    #+#             */
/*   Updated: 2025/05/09 16:39:00 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_setup_stdin(t_cmd *cmd, t_cmd *cmd_head, int prev_fds[2])
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

static void	_setup_stdout(t_cmd *cmd, int curr_fds[2])
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

static void	_setup_process_signals(void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

static pid_t	_fork_command(t_cmd *cmd, t_cmd *cmd_head, t_pipe_io *pipefds,
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
		return (_setup_process_signals(SIG_IGN), pid);
	_setup_stdin(cmd, cmd_head, pipefds->prev_fds);
	_setup_stdout(cmd, pipefds->curr_fds);
	_setup_process_signals(SIG_DFL);
	if ((cmd->next != NULL) && is_redirect(cmd->next))
		if(!redirect(cmd->next))
			exit(EXIT_FAILURE);
	if (is_builtin(cmd))
		exit(execute_builtin(cmd, minish));
	execute_cmd(cmd, minish);
	print_error(cmd->argv[0]);
	exit(EXIT_FAILURE);
}

/**
 * @brief Execute a pipeline of commands.
 *
 * For each command, create a pipe if needed, fork a child, redirect its
 * stdin/stdout through the pipes, and record its PID for waiting.
 *
 * @param cmd_head  First command in the pipeline.
 * @param minish    Shell context for built-ins and execution.
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
		cmd->pid = _fork_command(cmd, cmd_head, &pipefds, minish);
		cleanup_fds(pipefds.prev_fds);
		swap_fds(pipefds.prev_fds, pipefds.curr_fds);
		init_fds(pipefds.curr_fds);
		cmd = cmd->next;
	}
}
