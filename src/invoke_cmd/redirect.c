/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:19:19 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 16:57:45 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	redirect_stdout(t_cmd *cmd)
{
	int		fd;
	char	*path;

	path = cmd->argv[0];
	if (cmd->type == REDIR_OUT)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (cmd->type == REDIR_APPEND)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return ;
	if (fd < 0)
	{
		ft_putstr_fd("minish: ", STDERR_FILENO);
		perror(path);
		return ;
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minish: ", STDERR_FILENO);
		perror(path);
	}
	close(fd);
}

bool	is_limiter(int fd, char *limiter)
{
	char	*line;

	line = NULL;
	line = readline("> ");
	if (!line)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (true);
	}
	if (ft_strcmp(line, limiter) == 0)
	{
		free(line);
		return (true);
	}
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	free(line);
	return (false);
}

void	here_doc(char *limiter)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
	{
		ft_putstr_fd("minish: ", STDERR_FILENO);
		perror("pipe");
		return ;
	}
	while (!is_limiter(pipefd[1], limiter))
		;
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minish: ", STDERR_FILENO);
		perror("here_doc");
	}
	close(pipefd[0]);
}

void	redirect_stdin(t_cmd *cmd)
{
	int		fd;
	char	*path;

	path = cmd->argv[0];
	if (cmd->type == REDIR_HEREDOC)
	{
		here_doc(cmd->argv[0]);
		return ;
	}
	else if (cmd->type == REDIR_IN)
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("minish: ", STDERR_FILENO);
			perror(path);
			return ;
		}
		if (dup2(fd, STDIN_FILENO) < 0)
		{
			ft_putstr_fd("minish: ", STDERR_FILENO);
			perror(path);
		}
		close(fd);
	}
}

void	redirect(t_cmd *cmd)
{
	if (cmd->type == REDIR_IN || cmd->type == REDIR_HEREDOC)
		redirect_stdin(cmd);
	if (cmd->type == REDIR_OUT || cmd->type == REDIR_APPEND)
		redirect_stdout(cmd);
}
