/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:32 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 17:18:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		return (NULL);
	cmds = setup_cmds(cmds, expanded_tokens, minish);
	if (!cmds)
		return (NULL);
	return (cmds);
}
