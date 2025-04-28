/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/28 11:55:41 by ttsubo           ###   ########.fr       */
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
