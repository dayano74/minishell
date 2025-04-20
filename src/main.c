/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/20 20:41:20 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	destroy_minish(t_minish *minish)
{
	if (!minish)
		return ;
	free(minish);
	rl_clear_history();
}

static bool	prompt(t_minish *minish)
{
	char	*line;

	line = readline("minish>");
	if (!line)
		return (false);
	if (line[0] != '\0')
		add_history(line);
	free(line);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_minish	*minish;

	(void)argc;
	(void)argv;
	minish = initialize(envp);
	minish_signal();
	while (prompt(minish))
		;
	destroy_minish(minish);
	return (0);
}
