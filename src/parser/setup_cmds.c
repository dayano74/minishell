/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:38:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/18 15:26:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	_next_cmd(t_cmd **cmds, size_t *c_i, size_t *a_i, char *token)
{
	cmds[*c_i]->argv[*a_i] = NULL;
	cmds[*c_i]->argc = *a_i;
	(*a_i) = 0;
	(*c_i)++;
	set_cmd_type(cmds[*c_i], token);
	set_heredoc_flg(cmds[*c_i], token);
}

static bool	_copy_token(char **arg_p, char **token_p)
{
	size_t	len;

	if (!arg_p || !token_p || !*arg_p || !*token_p)
		return (false);
	len = ft_strlen(*token_p) + 1;
	return (ft_strlcpy(*arg_p, *token_p, len) < len);
}

t_cmd	**setup_cmds(t_cmd **cmds, char **tokens)
{
	size_t	t_i;
	size_t	c_i;
	size_t	a_i;

	t_i = 0;
	c_i = 0;
	a_i = 0;
	set_cmd_type(cmds[0], tokens[t_i]);
	set_heredoc_flg(cmds[0], tokens[t_i]);
	while (tokens[t_i])
	{
		if (is_separator(tokens[t_i]))
			_next_cmd(cmds, &c_i, &a_i, tokens[t_i]);
		else
		{
			tokens[t_i] = trim_quote_token(tokens[t_i]);
			if (!_copy_token(&(cmds[c_i]->argv[a_i]), &(tokens[t_i])))
				return (free_cmds(&cmds), NULL);
			a_i++;
		}
		t_i++;
	}
	cmds[c_i]->argc = a_i;
	return (cmds);
}
