/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/21 13:56:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief debug用　tokenを表示します。　後で削除予定。
 *
 * @param tokens
 */
static void	_dbg_show_tokens(char **tokens)
{
	printf("DEBUG: show tokens\n");
	printf("[");
	while (*tokens)
		printf("\"%s\", ", *tokens++);
	printf("NULL]\n");
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

static void	_destructor(char *line, char **tokens, t_minish *minish)
{
	if (line)
		free(line);
	if (tokens)
		_free_tokens(tokens);
	if (minish)
		free(minish);
t_cmd	*parse_command_line(char *line)
{
	(void)line;
	return (NULL);
}

int	invoke_commands(t_cmd *cmd)
{
	(void)cmd;
	return (0);
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
	t_cmd	*cmd;

	line = readline("minish>");
	if (!line)
		return (false);
	if (line[0] != '\0')
		add_history(line);
	tokens = tokenizer(line);
	_dbg_show_tokens(tokens);
	cmd = parse_command_line(line);
	if (!cmd)
	{
		error_mes(program_name, ": syntax error\n");
		cleanup_minish(minish);
		return (false);
	}
	if (cmd->argc > 0)
		*status = invoke_commands(cmd);
	_free_tokens(tokens);
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
