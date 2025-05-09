/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:19:33 by dayano            #+#    #+#             */
/*   Updated: 2025/05/09 15:58:38 by dayano           ###   ########.fr       */
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
	bool	redir_result;

	redir_result = true;
	builtin_cmd = cmd;
	if (cmd && cmd->next && is_redirect(cmd->next))
	{
		redir_result = redirect(cmd->next);
		if (redir_result && cmd->next)
			cmd = cmd->next;
		else
			return (print_error(cmd->argv[0]), EXIT_FAILURE);
	}
	if (cmd && cmd->next && is_redirect(cmd->next))
		redir_result = redirect(cmd->next);
	if (!redir_result)
		return (EXIT_FAILURE);
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
	int	original_stdin;
	int	original_stdout;

	status = 0;
	original_stdin = dup(STDIN_FILENO);
	original_stdout = dup(STDOUT_FILENO);
	if (is_unit_builtin(cmd_head))
		status = exec_unit_builtin(cmd_head, minish);
	else
	{
		exec_pipeline(cmd_head, minish);
		status = wait_pipeline(cmd_head);
		minish_signal();
	}
	close(STDIN_FILENO);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	close(STDOUT_FILENO);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (status);
}
