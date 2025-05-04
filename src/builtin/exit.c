/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 18:34:59 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_exit(int argc, char *argv[], t_minish *minish)
{
	long	status;
	char	*endptr;

	(void)minish;
	if (argc > 2)
		return (error_mes(argv[0], "too many arguments"), EXIT_FAILURE);
	if (printf("exit\n") < 0)
		return (perror("printf"), EXIT_FAILURE);
	if (argc == 1)
		exit(EXIT_SUCCESS);
	errno = 0;
	status = ft_strtol(argv[1], &endptr, 10);
	if (errno != 0 || *endptr != '\0')
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		error_mes(argv[1], "numeric argument required");
		exit(INCORRECT_USAGE);
	}
	exit((unsigned int)status);
}
