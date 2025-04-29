/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 13:06:39 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

	line = readline("$ ");
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
		minish->last_status = invoke_commands(cmds[0], minish);
	_free_tokens(tokens);
	free_cmds(cmds, cmds_len(cmds));
	free(line);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;
	char		*program_name;

	(void)argc;
	program_name = argv[0];
	minish = initialize(envp);
	minish_signal();
	while (prompt(program_name, minish))
		;
	destroy_minish(minish);
	return (minish->last_status);
}
