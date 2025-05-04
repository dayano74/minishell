/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:21:13 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 19:18:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVOKE_COMMAND_H
# define INVOKE_COMMAND_H

# include "common.h"
# include "create_envp.h"
# include "exec_pipeline.h"
# include "execute_cmd.h"
# include "pipeline_helper.h"
# include "redirect.h"
# include <wait.h>
# include <stdbool.h>

int		invoke_commands(t_cmd *cmd_head, t_minish *minish);
int		exec_unit_builtin(t_cmd *cmd, t_minish *minish);

// wait_pipeline.c
int		wait_pipeline(t_cmd *cmd_head);

// fds.c
void	init_fds(int fds[2]);
void	cleanup_fds(int fds1[2]);
void	swap_fds(int prev_fds[2], int curr_fds[2]);
void	create_pipe(bool need, int fds[2], t_cmd *cmd);

#endif
