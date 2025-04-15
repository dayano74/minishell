/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 14:45:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_minish	*_initialize(char **envp)
{
	t_minish	*minish;

	minish = ft_calloc(1, sizeof(t_minish));
	rl_clear_history();
	minish->envp = envp;
	return (minish);
}

static void	_destructor(char *line, t_minish *minish)
{
	if (line)
		free(line);
	if (minish)
		free(minish);
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;
	char		*line;
	
	(void)argc;
	(void)argv;
	minish = _initialize(envp);
	minish_signal();
	while (1)
	{
		line = readline("minish>");
		if (!line)
			break ;
		if (line[0] != '\0')
			add_history(line);
		free(line);
	}
	_destructor(line, minish);
	return (EXIT_SUCCESS);
}
