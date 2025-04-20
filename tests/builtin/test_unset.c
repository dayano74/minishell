/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:53:38 by dayano            #+#    #+#             */
/*   Updated: 2025/04/20 18:59:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int	_builtin_env(int argc, char **argv, t_minish *minish)
{
	t_env	*next;
	t_env	*current;

	(void)argv;
	if (argc != 1)
		return (ft_putstr_fd("error\n", STDERR_FILENO), EXIT_FAILURE);
	current = minish->env;
	while (current)
	{
		next = current->next;
		if (printf("%s\n", current->value) < 0)
			handle_error_and_exit("printf", minish);
		current = next;
	}
	return (EXIT_SUCCESS);
}

static size_t	_count_words(char **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

static void	cmds_free(char **cmds)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = _count_words(cmds);
	while (i < length)
		free(cmds[i++]);
	free(cmds);
}

static void	_exec_cmd(char *line, char **cmds, t_minish *minish)
{
	if (!ft_strcmp(cmds[0], "env"))
		builtin_env(_count_words(cmds), cmds, minish);
	if (!ft_strcmp(cmds[0], "unset"))
	{
		if (builtin_unset(_count_words(cmds), cmds, minish))
		{
			cmds_free(cmds);
			free(line);
			handle_error_and_exit("builtin-unset", minish);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**cmds;
	t_minish	*minish;

	(void)argc;
	(void)argv;
	minish = initialize(envp);
	while (1)
	{
		line = readline("minish>");
		if (!line)
			break ;
		if (line[0] == '\0')
			continue ;
		cmds = ft_split(line, ' ');
		_exec_cmd(line, cmds, minish);
		cmds_free(cmds);
		free(line);
	}
	cleanup_minish(minish);
	free(line);
	return (EXIT_SUCCESS);
}
