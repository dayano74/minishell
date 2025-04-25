/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:40:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/24 15:00:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perser.h"

size_t	cmds_len(t_cmd **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

void	free_cmds(t_cmd **cmds, size_t count)
{
	size_t	cmd_i;
	size_t	arg_i;

	cmd_i = 0;
	while (cmd_i < count)
	{
		arg_i = 0;
		while (cmds[cmd_i]->argv && cmds[cmd_i]->argv[arg_i])
			free(cmds[cmd_i]->argv[arg_i++]);
		free(cmds[cmd_i]->argv);
		free(cmds[cmd_i]);
		cmd_i++;
	}
	free(cmds);
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
