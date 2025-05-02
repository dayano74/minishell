/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:46:01 by dayano            #+#    #+#             */
/*   Updated: 2025/05/01 15:49:32 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_pwd(int argc, char *argv[], t_minish *minish)
{
	char	pwd[PATH_MAX];

	(void)minish;
	if (argc != 1)
	{
		error_mes(argv[0], "wrong argument");
		return (EXIT_FAILURE);
	}
	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		error_mes(argv[0], "cannot get working directory");
		return (EXIT_FAILURE);
	}
	if (printf("%s\n", pwd) < 0)
		return (perror("printf"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
