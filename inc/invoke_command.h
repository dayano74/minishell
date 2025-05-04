/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:21:13 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 18:14:32 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVOKE_COMMAND_H
# define INVOKE_COMMAND_H

# include "cmd.h"
# include <stdbool.h>

int		invoke_commands(t_cmd *cmd_head, t_minish *minish);
int		exec_unit_builtin(t_cmd *cmd, t_minish *minish);
int		execute_builtin(t_cmd *cmd, t_minish *minish);

// wait_pipeline.c
int		wait_pipeline(t_cmd *cmd_head);

// fds.c
void	init_fds(int fds[2]);
void	cleanup_fds(int fds1[2]);
void	swap_fds(int prev_fds[2], int curr_fds[2]);
void	create_pipe(bool need, int fds[2], t_cmd *cmd);

#endif
