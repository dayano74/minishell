/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_cmds_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:19:28 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 16:35:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**next_cmd_start(char **token_ptr)
{
	size_t	token_i;

	token_i = 0;
	while (token_ptr[token_i] && !is_separator(token_ptr[token_i]))
		token_i++;
	return (&token_ptr[token_i]);
}

t_cmd	**calloc_cmds(char **tokens)
{
	t_cmd	**cmds;
	size_t	cmd_i;
	size_t	token_i;

	token_i = 0;
	cmd_i = 1;
	while (tokens[token_i])
	{
		if (is_separator(tokens[token_i]))
			cmd_i++;
		token_i++;
	}
	cmds = ft_calloc(sizeof(t_cmd *), cmd_i + 1);
	return (cmds);
}

t_cmd	*calloc_cmd(void)
{
	return (ft_calloc(sizeof(t_cmd), 1));
}

char	**calloc_argv(char **tokens)
{
	size_t	token_i;

	token_i = 0;
	while (tokens[token_i] && !is_separator(tokens[token_i]))
		token_i++;
	return (ft_calloc(sizeof(char *), token_i + 1));
}

char	*calloc_arg(char *token)
{
	return (ft_strdup(token));
}
