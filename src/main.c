/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 21:05:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_minish(t_minish *minish)
{
	cleanup_minish(minish);
	rl_clear_history();
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
	char	*line;
	char	**tokens;
	t_cmd	**cmds;

	tokens = NULL;
	cmds = NULL;
	line = readline("$ ");
	if (!line)
		return (free_prompt(&tokens, &cmds, &line), false);
	if (line[0] != '\0')
		add_history(line);
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
