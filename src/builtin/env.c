/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:19:11 by dayano            #+#    #+#             */
/*   Updated: 2025/04/15 10:48:56 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// env with no options or arguments

static void	_error_mes(char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
}

int	builtin_env(int argc, char *argv[], char *envp[])
{
	int	i;

	if (argc != 1)
		return (_error_mes(argv[0]), EXIT_FAILURE);
	i = 0;
	while (envp[i] != NULL)
	{
		if (printf("%s\n", envp[i]) < 0)
			return (perror("printf"), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
