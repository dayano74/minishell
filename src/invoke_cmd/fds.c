/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:45:58 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 16:46:03 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_fds(int fds[2])
{
	fds[0] = -1;
	fds[1] = -1;
}

void	cleanup_fds(int fds1[2])
{
	if (fds1[0] != -1)
		close(fds1[0]);
	if (fds1[1] != -1)
		close(fds1[1]);
}

void	swap_fds(int prev_fds[2], int curr_fds[2])
{
	prev_fds[0] = curr_fds[0];
	prev_fds[1] = curr_fds[1];
}

void	create_pipe(bool need, int fds[2], t_cmd *cmd)
{
	if (!need)
	{
		fds[0] = -1;
		fds[1] = -1;
		return ;
	}
	if (pipe(fds) < 0)
	{
		print_error(cmd->argv[0]);
		exit(EX_OSERR);
	}
}
