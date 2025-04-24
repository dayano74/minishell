/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:25:41 by dayano            #+#    #+#             */
/*   Updated: 2025/04/24 14:09:02 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*find_cmd_in_paths(char **path_set, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (path_set[i])
	{
		full_path = join_path(path_set[i], cmd);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_line;
	char	**path_set;
	char	*full_path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	path_line = get_path_line(envp);
	if (!path_line)
		return (NULL);
	path_set = ft_split(path_line, ':');
	if (!path_set)
		return (NULL);
	full_path = find_cmd_in_paths(path_set, cmd);
	free_str_array(path_set);
	return (full_path);
}

bool	is_pathname(char *cmd, char **envp, char **fullpath)
{
	*fullpath = get_cmd_path(cmd, envp);
	if (!*fullpath)
		return (false);
	return (true);
}

void	execute_cmd(t_cmd *cmd, t_minish *minish)
{
	char	*fullpath;
	char	**envp;

	envp = create_envp(minish);
	if (!envp)
	{
		perror("create_envp");
	}
	if (!cmd->argv[0] || ft_strlen(cmd->argv[0]) == 0)
	{
		ft_putstr_fd("Command '' not found\n", STDERR_FILENO);
		exit(127);
	}
	if (!is_pathname(cmd->argv[0], envp, &fullpath))
	{
		ft_putstr_fd("Command '' not found\n", STDERR_FILENO);
		exit(127);
	}
	if (execve(fullpath, cmd->argv, envp) < 0)
	{
		free(fullpath);
		perror("execve");
	}
}
