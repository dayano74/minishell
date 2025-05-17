/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:14:15 by dayano            #+#    #+#             */
/*   Updated: 2025/05/17 16:54:01 by ttsubo           ###   ########.fr       */
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
		pipeline_exit(EX_OSERR, minish);
	}
	if (pid > 0)
		return (_setup_process_signals(SIG_IGN), pid);
	if (cmd->next && cmd->next->type == REDIR_HEREDOC)
		here_doc(cmd->next->argv[0], minish);
	_setup_stdin(cmd, cmd_head, pipefds->prev_fds);
	_setup_stdout(cmd, pipefds->curr_fds);
	_setup_process_signals(SIG_DFL);
	handle_all_redirection(cmd, minish);
	if (is_builtin(cmd))
		pipeline_exit(execute_builtin(cmd, minish), minish);
	execute_cmd(cmd, minish);
	pipeline_exit(EXIT_FAILURE, minish);
	return (EXIT_FAILURE);
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
	while (cmd)
	{
		if (is_redirect(cmd))
		{
			cmd = cmd->next;
			continue ;
		}
		need_pipe = !is_tail(cmd);
		create_pipe(need_pipe, pipefds.curr_fds, cmd);
		cmd->pid = _fork_command(cmd, cmd_head, &pipefds, minish);
		cleanup_fds(pipefds.prev_fds);
		swap_fds(pipefds.prev_fds, pipefds.curr_fds);
		init_fds(pipefds.curr_fds);
		cmd = cmd->next;
	}
}
