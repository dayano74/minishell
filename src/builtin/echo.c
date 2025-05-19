/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/19 16:14:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	_echo_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static int	_echo_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}

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

	if (arg[0] != '-' || ft_strcmp(arg, "-") == 0)
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
 * @return 0: success. 1: output failed.
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
		if (_echo_putstr_fd(argv[i++], STDOUT_FILENO) == -1)
			return (1);
		if (i != argc && _echo_putchar_fd(' ', STDOUT_FILENO) == -1)
			return (1);
	}
	if (nl_flg && _echo_putchar_fd('\n', STDOUT_FILENO) == -1)
		return (1);
	return (0);
}
