/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:19:33 by dayano            #+#    #+#             */
/*   Updated: 2025/05/18 16:47:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Determine whether the command list represents a standalone builtin.
 *        Builtins include commands like cd, echo, export, exit, and pwd,
 *        and should be executed without forking when they appear alone.
 * @note to be implemented later
 * @param cmd_head
 * @return true
 * @return false
 */
static bool	is_unit_builtin(t_cmd *cmd_head)
{
	t_cmd	*cmd;

	cmd = cmd_head;
	if (cmd == NULL)
		return (false);
	if (!is_builtin(cmd))
		return (false);
	cmd = cmd->next;
	while (cmd != NULL && is_redirect(cmd))
		cmd = cmd->next;
	return (cmd == NULL);
}

int	execute_builtin(t_cmd *cmd, t_minish *minish)
{
	static const t_builtin	builtin_funcs[] = {builtin_echo, builtin_pwd,
		builtin_exit, builtin_cd, builtin_env, builtin_export,
		builtin_unset, NULL};
	static char				*builtin_list[] = {"echo", "pwd", "exit", "cd",
		"env", "export", "unset", NULL};
	int						i;

	i = 0;
	while (builtin_list[i])
	{
		if (!ft_strcmp(cmd->argv[0], builtin_list[i]))
			return (builtin_funcs[i](cmd->argc, cmd->argv, minish));
		i++;
	}
	return (print_error(cmd->argv[0]), EXIT_FAILURE);
}

/**
 * @brief Execute a standalone builtin command directly in the current process.
 *        Does not spawn a child process. Handles builtins such as cd (chdir),
 *        export (environment update), exit (shell termination), etc.
 * @note to be implemented later
 * @param cmd_head
 * @return int
 */
int	exec_unit_builtin(t_cmd *cmd, t_minish *minish)
{
	t_cmd	*builtin_cmd;
	t_cmd	*redir_cmd;
	bool	redir_result;

	builtin_cmd = cmd;
	redir_cmd = cmd->next;
	while (redir_cmd && is_redirect(redir_cmd))
	{
		redir_result = redirect(redir_cmd, minish);
		if (!redir_result)
			return (print_error(builtin_cmd->argv[0]), EXIT_FAILURE);
		redir_cmd = redir_cmd->next;
	}
	return (execute_builtin(builtin_cmd, minish));
}

/**
 * @brief Save and restore the original stdin and stdout file descriptors,
 *        then execute commands—either a standalone builtin or, otherwise,
 *        an external command sequence (pipeline).
 * @param cmd_head
 * @return int
 */
int	invoke_commands(t_cmd *cmd_head, t_minish *minish)
{
	int	status;

	status = 0;
	minish->org_stdin = dup(STDIN_FILENO);
	minish->org_stdout = dup(STDOUT_FILENO);
	if (is_unit_builtin(cmd_head))
		status = exec_unit_builtin(cmd_head, minish);
	else
	{
		exec_pipeline(cmd_head, minish);
		status = wait_pipeline(cmd_head);
		minish_signal();
	}
	close_fd(STDIN_FILENO, minish->org_stdin);
	close_fd(STDOUT_FILENO, minish->org_stdout);
	return (status);
}
