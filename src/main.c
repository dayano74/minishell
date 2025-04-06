/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/06 16:20:07 by ttsubo           ###   ########.fr       */
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
	while (1)
	{
		line = readline("minish>");
		if (!line)
			break ;
		add_history(line);
		free(line);
	}
	_destructor(line);
	return (EXIT_SUCCESS);
}
