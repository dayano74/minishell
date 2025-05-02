/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:32 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 19:08:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	_free_tokens(char **tokens)
{
	size_t	token_i;

	token_i = 0;
	while (tokens[token_i])
		token_i++;
	while (0 < token_i)
		free(tokens[--token_i]);
	free(tokens);
}

/**
 * @brief
 *
 * @param tokens
 * @return t_cmd**
 */
t_cmd	**parser(char **tokens, t_minish *minish)
{
	char	**expanded_tokens;
	t_cmd	**cmds;

	expanded_tokens = expand_tokens(tokens, minish);
	if (!expanded_tokens)
		return (NULL);
	cmds = allocate_cmds(expanded_tokens);
	if (!cmds)
		return (_free_tokens(expanded_tokens), NULL);
	cmds = setup_cmds(cmds, expanded_tokens);
	if (!cmds)
		return (_free_tokens(expanded_tokens), NULL);
	_free_tokens(expanded_tokens);
	return (cmds);
}
