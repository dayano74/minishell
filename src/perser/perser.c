/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:32 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/24 13:38:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perser.h"

/**
 * @brief 
 * 
 * @param tokens 
 * @return t_cmd* 
 */
t_cmd	*perser(char **tokens)
{
	t_cmd	**cmds;
	t_cmd	*cmd;

	cmds = allocate_cmds(tokens);
	if (!cmds)
		return (NULL);
	return (cmds);
}
