/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/04/13 22:34:13 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	builtin_exit(int argc, char *argv[])
{
	if (argc != 1)
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
		return (1);
	}
	if (printf("exit\n") < 0)
		return (1);
	exit(EXIT_SUCCESS);
}

// #include <readline/readline.h>

// int	main(void)
// {
// 	char	*line;
// 	char	**strings_line;

// 	while (1)
// 	{
// 		line = readline("minish>");
// 		if (!line)
// 			break ;
// 		if (strcmp("exit", line) == 0)
// 		{
// 			strings_line = ft_split(line, ' ');
// 			if (builtin_exit(3, strings_line) == 1)
// 			{
// 				printf("error\n");
// 				free(line);
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		free(line);
// 	}
// 	return (EXIT_SUCCESS);
// }
