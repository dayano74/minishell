/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:32 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/21 14:39:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perser.h"

static void _clean_cmds(t_cmd *cmd, t_cmd **cmds)
{
	if ()
}

// liner list
t_cmd	*perser(char **tokens)
{
	int		i;
	t_cmd	**cmds;
	t_cmd	*cmd;

	i = 0;
	while (tokens[i])
	{
		cmd = ft_calloc(1, sizeof(t_cmd));
		if (!cmd)
			return (_clean_cmds(cmd, cmds));
		*cmd = (t_cmd){.capa=-1, .pid=-1, .status=-1};
		free(cmd);
		i++;
	}
	return (cmds);
}