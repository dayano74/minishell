/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:19:33 by dayano            #+#    #+#             */
/*   Updated: 2025/05/01 14:18:31 by dayano           ###   ########.fr       */
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
	if (is_redirect)
		cmd = cmd->next;
	if ((is_builtin(cmd) && cmd->next == NULL) || (is_builtin(cmd)
			&& is_redirect(cmd->next)))
		return (true);
	else
		return (false);
}

/**
 * @brief Execute a standalone builtin command directly in the current process.
 *        Does not spawn a child process. Handles builtins such as cd (chdir),
 *        export (environment update), exit (shell termination), etc.
 * @note to be implemented later
 * @param cmd_head
 * @return int
 */
int	exec_unit_builtin(t_cmd *cmd_head)
{
	(void)cmd_head;
	return (0);
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
	int	original_stdin;
	int	original_stdout;

	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if (is_unit_builtin(cmd_head))
		status = exec_unit_builtin(cmd_head);
	else
	{
		exec_pipeline(cmd_head, minish);
		status = wait_pipeline(cmd_head);
	}
	close(STDIN_FILENO);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	close(STDOUT_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (status);
}
