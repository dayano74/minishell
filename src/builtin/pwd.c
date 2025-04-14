/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:46:01 by dayano            #+#    #+#             */
/*   Updated: 2025/04/14 16:04:36 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_error_mes(char *name, char *mes)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(mes, STDERR_FILENO);
}

int	builtin_pwd(int argc, char *argv[])
{
	char	pwd[PATH_MAX];

	if (argc != 1)
	{
		_error_mes(argv[0], ": wrong argument\n");
		return (EXIT_FAILURE);
	}
	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		_error_mes(argv[0], ": cannot get working directory\n");
		return (EXIT_FAILURE);
	}
	if (printf("%s\n", pwd) < 0)
		return (perror("printf"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
