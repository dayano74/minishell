/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/05/19 15:38:46 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_exec_exit(unsigned int status, t_minish *minish)
{
	close_fd(STDIN_FILENO, minish->org_stdin);
	close_fd(STDOUT_FILENO, minish->org_stdout);
	exit(status);
}

int	builtin_exit(int argc, char *argv[], t_minish *minish)
{
	long	status;
	char	*endptr;

	(void)minish;
	if (printf("exit\n") < 0)
		return (perror("printf"), EXIT_FAILURE);
	if (argc == 1)
		_exec_exit(EXIT_SUCCESS, minish);
	if (argc >= 2)
	{
		errno = 0;
		status = ft_strtol(argv[1], &endptr, 10);
		if (errno != 0 || *endptr != '\0')
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			error_mes(argv[1], "numeric argument required");
			_exec_exit(INCORRECT_USAGE, minish);
		}
		if (argc >= 3)
			return (ft_putstr_fd("minishell: exit: too many arguments\n",
					STDERR_FILENO), EXIT_FAILURE);
		_exec_exit(status, minish);
	}
	return (EXIT_SUCCESS);
}
