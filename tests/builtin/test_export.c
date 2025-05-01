/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:53:38 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 13:52:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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

static void	_exec_cmd(char **cmds, t_minish *minish)
{
	if (!ft_strcmp(cmds[0], "env"))
		builtin_env(_count_words(cmds), cmds, minish);
	if (!ft_strcmp(cmds[0], "export"))
		builtin_export(_count_words(cmds), cmds, minish);
	if (!ft_strcmp(cmds[0], "unset"))
		builtin_unset(_count_words(cmds), cmds, minish);
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
		_exec_cmd(cmds, minish);
		add_history(line);
		cmds_free(cmds);
		free(line);
	}
	cleanup_minish(minish);
	rl_clear_history();
	free(line);
	return (EXIT_SUCCESS);
}
