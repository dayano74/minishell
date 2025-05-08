/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/08 17:00:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_minish(t_minish *minish)
{
	cleanup_minish(minish);
	rl_clear_history();
}

static t_read_result	_read_user_input(char **line)
{
	*line = readline("$ ");
	if (!*line)
		return (READ_EOF);
	if ((*line)[0] == '\0')
		return (READ_EMPTY);
	add_history(*line);
	return (READ_OK);
}

static void	_set_g_sig_sts(t_minish *minish)
{
	if (g_sig_sts)
	{
		minish->last_status = g_sig_sts;
		g_sig_sts = 0;
	}
}

/**
 * @brief I used bool type since it seems to be available.
 * @param program_name
 * @param minish
 * @return true
 * @return false
 */
static bool	prompt(char *program_name, t_minish *minish)
{
	char			*line;
	char			**tokens;
	t_cmd			**cmds;
	t_read_result	res;

	res = _read_user_input(&line);
	if (res == READ_EOF)
		return (free_str(&line), false);
	if (res == READ_EMPTY)
		return (free_str(&line), true);
	_set_g_sig_sts(minish);
	tokens = tokenizer(line);
	cmds = parser(tokens, minish);
	if (!cmds)
	{
		error_mes(program_name, ": syntax error\n");
		free_prompt(&tokens, &cmds, &line);
		cleanup_minish(minish);
		return (false);
	}
	if (cmds[0]->argc > 0)
		minish->last_status = invoke_commands(cmds[0], minish);
	free_prompt(&tokens, &cmds, &line);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;
	char		*program_name;
	int			last_status;

	(void)argc;
	program_name = argv[0];
	minish = initialize(envp);
	minish_signal();
	while (prompt(program_name, minish))
		;
	last_status = minish->last_status;
	destroy_minish(minish);
	return (last_status);
}
