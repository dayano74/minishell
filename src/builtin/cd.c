/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/14 11:21:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_error_mes(char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": wrong argument\n", STDERR_FILENO);
}

int	builtin_cd(int argc, char *argv[])
{
	if (argc != 2)
		return (_error_mes(argv[0]), EXIT_FAILURE);
	if (chdir(argv[1]) < 0)
		return (perror(argv[1]), 1);
	return (0);
}
