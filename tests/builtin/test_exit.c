/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:48:09 by dayano            #+#    #+#             */
/*   Updated: 2025/04/14 15:27:43 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	char	**strings_line;

	while (1)
	{
		line = readline("minish>");
		if (!line)
			break ;
		if (strcmp("exit", line) == 0)
		{
			strings_line = ft_split(line, ' ');
			if (builtin_exit(1, strings_line) == 1) // argcは手動で操作する必要あり
			{
				printf("error\n");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
