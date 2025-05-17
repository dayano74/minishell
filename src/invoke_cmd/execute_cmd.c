/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:25:41 by dayano            #+#    #+#             */
/*   Updated: 2025/05/17 15:46:27 by dayano           ###   ########.fr       */
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

	full_path = NULL;
	if (!cmd && ft_strlen(cmd) == 0)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
	}
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

void	execute_cmd(t_cmd *cmd, t_minish *minish)
{
	char	*fullpath;
	char	**envp;

	envp = create_envp(minish);
	if (!envp)
		return (print_cmd_not_found(cmd));
	fullpath = get_cmd_path(cmd->argv[0], envp);
	if (access(fullpath, F_OK) < 0)
		return (free_strs(&envp), print_cmd_not_found(cmd));
	if (access(fullpath, X_OK) < 0)
	{
		free_strs(&envp);
		print_error(cmd->argv[0]);
		cmd->status = CMD_FAILED_EXIT_STATUS;
		exit(CMD_FAILED_EXIT_STATUS);
		return ;
	}
	if (execve(fullpath, cmd->argv, envp) < 0)
	{
		free(fullpath);
		cmd->status = CMD_FAILED_EXIT_STATUS;
		exit(CMD_FAILED_EXIT_STATUS);
	}
}
