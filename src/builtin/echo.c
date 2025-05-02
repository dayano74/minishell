/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/01 15:48:48 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief Determines if the option is n only.
 *
 * @param arg
 * @return 0: Contains other than n
 * @return 1: only n
 */
static int	_has_only_n_option(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief The built-in echo command.
 *
 * @param argc
 * @param argv
 * @return 0: Always returns 0.
 */
int	builtin_echo(int argc, char *argv[], t_minish *minish)
{
	int	i;
	int	nl_flg;

	(void)minish;
	i = 1;
	nl_flg = 1;
	while (i < argc)
	{
		if (_has_only_n_option(argv[i]))
			nl_flg = 0;
		else
			break ;
		i++;
	}
	while (i < argc)
	{
		ft_putstr_fd(argv[i++], STDOUT_FILENO);
		if (i != argc)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (nl_flg)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
