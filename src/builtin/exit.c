/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 17:13:57 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_exit(int argc, char *argv[], t_minish *minish)
{
	(void)minish;
	if (argc > 2)
		return (error_mes(argv[0], "too many arguments"), EXIT_FAILURE);
	if(argc == 1)
	{
		if (printf("exit\n") < 0)
			return (perror("printf"), EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (printf("exit\n") < 0)
			return (perror("printf"), EXIT_FAILURE);
		exit(argv[1]);
	}
}
