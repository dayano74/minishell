/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:19:28 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/24 14:37:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perser.h"


static size_t	_count_cmds(char **tokens)
{
	size_t	i;
	size_t	cmd_count;

	i = 0;
	cmd_count = 1;
	while (tokens[i])
	{
		if (is_separator(tokens[i]))
			cmd_count++;
		i++;
	}
	return (cmd_count);
}

static t_cmd	**_allocate_cmds(size_t count)
{
	size_t	i;
	t_cmd	**cmds;

	i = 0;
	cmds = ft_calloc(count, sizeof(t_cmd *) + 1);
	if (!cmds)
		return (NULL);
	while (i < count)
	{
		cmds[i] = ft_calloc(1, sizeof(t_cmd));
		if (!cmds[i])
			return (free_cmds(cmds, i), NULL);
		if (i > 0)
			cmds[i - 1]->next = cmds[i];
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

t_cmd	**allocate_cmds(char **tokens)
{
	t_cmd	**cmds;

	cmds = _allocate_cmds(_count_cmds(tokens));
	if (!cmds)
		return (NULL);
	return (cmds);
}
