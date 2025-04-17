/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 12:24:30 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief オプションがnのみか判定します
 *
 * @param arg1
 * @return 0: n以外が含まれている
 * @return 1: nのみ
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
 * @brief built-inのechoコマンドです。
 *
 * @param argc
 * @param argv
 * @return 0: 常に0を返します。
 */
int	builtin_echo(int argc, char *argv[])
{
	int	i;
	int	nl_flg;

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
