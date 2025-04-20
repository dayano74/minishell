/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/20 20:14:26 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_minish(t_minish *minish)
{
	if (minish)
		free(minish);
	rl_clear_history();
}

static int	prompt(t_minish *minish)
{
	char	*line;

	line = readline("minish>");
	if (!line)
		return (EXIT_FAILURE);
	if (line[0] != '\0')
		add_history(line);
	free(line);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;

	(void)argc;
	(void)argv;
	minish = initialize(envp);
	minish_signal();
	while (1)
	{
		if (prompt(minish))
			break ;
	}
	destroy_minish(minish);
	return (EXIT_SUCCESS);
}
