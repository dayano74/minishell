/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:12:27 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 12:33:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPELINE_H
# define EXEC_PIPELINE_H

# include "cmd.h"
# include "common.h"
# include "execute_cmd.h"
# include "invoke_command.h"
# include "pipeline_helper.h"
# include "struct.h"
# include "redirect.h"
# include <sysexits.h>

typedef struct s_pipe_io
{
	int	prev_fds[2];
	int	curr_fds[2];
}		t_pipe_io;

void	exec_pipeline(t_cmd *cmd_head, t_minish *minish);
int		wait_pipeline(t_cmd *cmd_head);

#endif
