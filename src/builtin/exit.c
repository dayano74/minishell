/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/04/14 15:26:25 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_error_mes(char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
}

int	builtin_exit(int argc, char *argv[])
{
	if (argc != 1)
		return (_error_mes(argv[0]), EXIT_FAILURE);
	if (printf("exit\n") < 0)
		return (perror("printf"), EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
