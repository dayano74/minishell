/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/17 12:30:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_cd(int argc, char *argv[], t_minish *minish)
{
	const char	*home = get_env_value(minish->env, "HOME");

	if (!home)
		return (error_mes("bash: cd", "HOME not set"), EXIT_FAILURE);
	if (argc == 1)
	{
		if (chdir(home) < 0)
			return (perror(home), 1);
	}
	else if (argc == 2)
	{
		if (chdir(argv[1]) < 0)
			return (perror(argv[1]), 1);
	}
	else
		return (error_mes(argv[0], "too many arguments"), EXIT_FAILURE);
	return (0);
}
