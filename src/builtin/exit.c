/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:20:48 by dayano            #+#    #+#             */
/*   Updated: 2025/04/13 21:40:27 by dayano           ###   ########.fr       */
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
	exit(EXIT_SUCCESS);
}
