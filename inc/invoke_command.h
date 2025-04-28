/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:21:13 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 21:21:30 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVOKE_COMMAND_H
# define INVOKE_COMMAND_H

# include "cmd.h"

int	invoke_commands(t_cmd *cmd_head, t_minish *minish);
int	exec_unit_builtin(t_cmd *cmd_head);

#endif
