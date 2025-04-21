/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/21 13:37:49 by ttsubo           ###   ########.fr       */
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
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;
	char		*line;
	char		**tokens;

	(void)argc;
	(void)argv;
	minish = initialize(envp);
	minish_signal();
	while (1)
	{
		line = readline("minish>");
		if (!line)
			break ;
		if (line[0] != '\0')
			add_history(line);
		tokens = tokenizer(line);
		_dbg_show_tokens(tokens);
		_free_tokens(tokens);
		free(line);
	}
	_destructor(line, tokens, minish);
	return (EXIT_SUCCESS);
}
