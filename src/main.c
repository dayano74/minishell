/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/26 11:48:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief debug用　cmdを表示します。　後で削除予定。
 *
 * @param tokens
 */
static void	_dbg_show_cmd(t_cmd **cmds)
{
	size_t	cmd_i;
	size_t	arg_i;

	cmd_i = 0;
	printf("DEBUG: show cmds\n");
	while (cmds[cmd_i])
	{
		arg_i = 0;
		printf("cmd[%zu]\n", cmd_i);
		printf("\tcmd->type=%d\n", cmds[cmd_i]->type);
		printf("\tcmd->argc=%d\n", cmds[cmd_i]->argc);
		printf("\tcmd->argv=[");
		while (cmds[cmd_i]->argv[arg_i])
			printf("%s,", cmds[cmd_i]->argv[arg_i++]);
		printf("NULL]\n");
		cmd_i++;
	}
}

static void	_free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		tokens[i++] = NULL;
	}
	free(tokens);
	tokens = NULL;
}

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
	char	**tokens;
	t_cmd	**cmds;

	(void) status;
	line = readline("minish>");
	if (!line)
		return (false);
	if (line[0] != '\0')
		add_history(line);
	tokens = tokenizer(line);
	cmds = parser(tokens, minish);
	if (!cmds)
	{
		error_mes(program_name, ": syntax error\n");
		cleanup_minish(minish);
		return (false);
	}
	if (cmds[0]->argc > 0)
		*status = invoke_commands(cmds[0], minish);
	_dbg_show_cmd(cmds);
	_free_tokens(tokens);
	free_cmds(cmds, cmds_len(cmds));
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
