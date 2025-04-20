/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/20 21:25:55 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_minish(t_minish *minish)
{
	cleanup_minish(minish);
	rl_clear_history();
}

/**
 * @brief bool型が利用できるみたいなので、使用してみました。
 * @brief parse_command_lineのプロトタイプを勝手に作成しているので、好きなように改変していただいて大丈夫です
 * @param program_nam
 * @param minish
 * @return true
 * @return false
 */
static bool	prompt(char *program_name, t_minish *minish, int *status)
{
	char	*line;
	t_cmd	*cmd;

	line = readline("minish>");
	if (!line)
		return (false);
	if (line[0] != '\0')
		add_history(line);
	cmd = parse_command_line(line);
	if (!cmd)
		return (error_mes(program_name, ": syntax error\n"), false);
	if (cmd->argc > 0)
		*status = invoke_commands(cmd);
	free(line);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;
	char		*program_name;
	int			exit_status;

	(void)argc;
	program_name = argv[0];
	minish = initialize(envp);
	minish_signal();
	while (prompt(program_name, minish, &exit_status))
		;
	destroy_minish(minish);
	return (exit_status);
}
