/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/13 13:44:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_initialize(void)
{
	rl_clear_history();
}

static void	_destructor(char *line)
{
	if (!line)
		free(line);
	rl_clear_history();
}

int	main(void)
{
	char	*line;

	_initialize();
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
	_destructor(line);
	return (EXIT_SUCCESS);
}
