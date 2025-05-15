/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:32 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/15 15:48:56 by ttsubo           ###   ########.fr       */
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
	char	**formatted_tokens;
	t_cmd	**cmds;

	if (!tokens)
		return (NULL);
	formatted_tokens = expand_tokens(tokens, minish);
	if (!formatted_tokens)
		return (NULL);
	formatted_tokens = trim_quote_tokens(formatted_tokens);
	cmds = allocate_cmds(formatted_tokens);
	if (!cmds)
		return (free_strs(&formatted_tokens), NULL);
	cmds = setup_cmds(cmds, formatted_tokens);
	if (!cmds)
		return (free_strs(&formatted_tokens), NULL);
	free_strs(&formatted_tokens);
	return (cmds);
}
