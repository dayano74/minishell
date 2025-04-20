/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/04/20 19:53:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_exit(int argc, char *argv[])
{
	if (argc != 1)
		return (error_mes(argv[0], "too many arguments"), EXIT_FAILURE);
	if (printf("exit\n") < 0)
		return (perror("printf"), EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
