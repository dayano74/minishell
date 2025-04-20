/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:19:33 by dayano            #+#    #+#             */
/*   Updated: 2025/04/20 21:47:46 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	is_unit_builtin(t_cmd *cmd_head);
static int	exec_unit_builtin(t_cmd *cmd_head);
static void	exec_pipeline(t_cmd *cmd_head);
static int	wait_pipeline(t_cmd *cmd_head);

int	invoke_commands(t_cmd *cmd_head)
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
		exec_pipeline(cmd_head);
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
