/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:19:33 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 13:19:41 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	is_unit_builtin(t_cmd *cmd_head);
static int	exec_unit_builtin(t_cmd *cmd_head);

/**
 * @brief fdの0, 1, 2をもとに戻せるように確保し、コマンド実行後に戻す。
 * @brief コマンドの実行はビルトインコマンド単体 or それ以外（外部関数やパイプ）
 * @brief に分岐処理する。
 *
 * @param cmd_head
 * @return int
 */
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
