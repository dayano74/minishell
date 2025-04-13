/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:46:01 by dayano            #+#    #+#             */
/*   Updated: 2025/04/13 21:09:08 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include <unistd.h>

// builtin command
// pwd with no options

int	builtin_pwd(int argc, char *argv[])
{
	char	pwd[PATH_MAX];

	if (argc != 1)
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": wrong argument\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": cannot get working directory\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (ft_printf("%s\n", pwd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	int	i;

// 	// printf{"=====check function====="};
// 	// printf("argc = %d\n", argc);
// 	// i = 0;
// 	// while (argv[i])
// 	// {
// 	// 	printf("argv[%d] = %s\n", i, argv[i]);
// 	// 	i++;
// 	// }
// 	// printf("========================");
// 	if (builtin_pwd(argc, argv))
// 		printf("error\n");
// 	return (0);
// }
