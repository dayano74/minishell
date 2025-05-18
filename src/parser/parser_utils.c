/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:40:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/18 15:59:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_heredoc_flg(t_cmd *cmd, char *token)
{
	bool	has_quote;

	has_quote = ft_strchr(token, '\'') != NULL
		|| ft_strchr(token, '"') != NULL;
	cmd->is_expand_heredoc = !(cmd->type == REDIR_HEREDOC && has_quote);
}

void	set_cmd_type(t_cmd *cmd, char *token)
{
	if (!ft_strcmp(token, ">"))
		cmd->type = REDIR_OUT;
	else if (!ft_strcmp(token, ">>"))
		cmd->type = REDIR_APPEND;
	else if (!ft_strcmp(token, "<"))
		cmd->type = REDIR_IN;
	else if (!ft_strcmp(token, "<<"))
		cmd->type = REDIR_HEREDOC;
	else
		cmd->type = REDIR_NONE;
}

size_t	count_args_until_separator(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i] && !is_separator(tokens[i]))
		i++;
	return (i);
}

size_t	cmds_len(t_cmd **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

int	is_separator(char *token)
{
	return (!ft_strcmp(token, "|")
		|| !ft_strcmp(token, "<")
		|| !ft_strcmp(token, ">")
		|| !ft_strcmp(token, "<<")
		|| !ft_strcmp(token, ">>")
	);
}
