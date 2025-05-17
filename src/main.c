/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/17 16:26:47 by ttsubo           ###   ########.fr       */
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
	if (is_line_empty(*line))
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
static bool	prompt(t_minish *minish)
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
		return (free_prompt(&tokens, &cmds, &line), true);
	if (cmds[0]->argc > 0)
		minish->last_status = invoke_commands(cmds[0], minish);
	free_prompt(&tokens, &cmds, &line);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;
	int			last_status;

	(void)argc;
	minish = initialize(envp);
	minish_signal();
	while (prompt(minish))
		;
	last_status = minish->last_status;
	destroy_minish(minish);
	return (last_status);
}
