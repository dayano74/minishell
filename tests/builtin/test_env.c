/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:24:45 by dayano            #+#    #+#             */
/*   Updated: 2025/04/18 16:11:30 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		if (!ft_strcmp(cmds[0], "env"))
			builtin_env(_count_words(cmds), cmds, minish);
		cmds_free(cmds);
		free(line);
	}
	cleanup_minish(minish);
	free(line);
	return (EXIT_SUCCESS);
}
