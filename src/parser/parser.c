/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:32 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/25 18:19:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief 
 * 
 * @param tokens 
 * @return t_cmd** 
 */
t_cmd	**parser(char **tokens)
{
	t_cmd	**cmds;

	cmds = allocate_cmds(tokens);
	if (!cmds)
		return (NULL);
	cmds = setup_cmds(cmds, tokens);
	if (!cmds)
		return (NULL);
	return (cmds);
}
