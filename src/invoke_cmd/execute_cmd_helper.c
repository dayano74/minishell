/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:37:20 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 17:04:58 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_cmd_not_found(t_cmd *cmd)
{
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	cmd->status = CMD_NOT_FOUND_EXIT_STATUS;
	exit(CMD_NOT_FOUND_EXIT_STATUS);
}

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*get_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", PATH_PREFIX_LEN) == 0)
			return (envp[i] + PATH_PREFIX_LEN);
		i++;
	}
	return (NULL);
}

char	*join_path(char *dir, char *cmd)
{
	char	*full_path;
	int		len_dir;
	int		len_cmd;

	if (dir[ft_strlen(dir) - 1] == '/')
	{
		full_path = ft_strjoin(dir, cmd);
		if (!full_path)
			return (NULL);
		return (full_path);
	}
	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	full_path = malloc(len_dir + len_cmd + 2);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len_dir + 1);
	full_path[len_dir] = '/';
	full_path[len_dir + 1] = '\0';
	ft_strlcpy(full_path + len_dir + 1, cmd, len_cmd + 1);
	return (full_path);
}
