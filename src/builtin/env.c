/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:19:11 by dayano            #+#    #+#             */
/*   Updated: 2025/04/17 15:20:41 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_error_mes(char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
}

int	builtin_env(int argc, char **argv, t_minish *minish)
{
	t_env	*next;
	t_env	*current;

	if (argc != 1)
		return (_error_mes(argv[0]), EXIT_FAILURE);
	current = minish->env;
	while (current)
	{
		next = current->next;
		if (printf("%s\n", current->value) < 0)
			handle_error_and_exit("printf", minish);
		current = next;
	}
	return (EXIT_SUCCESS);
}
