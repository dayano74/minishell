/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:32:27 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 14:11:40 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_HELPER_H
# define PIPELINE_HELPER_H

# include "cmd.h"
# include <stdbool.h>

// pipeline_helper.c
void	redirect_stdout(t_cmd *cmd);
bool	is_redirect(t_cmd *cmd);
bool	is_head(t_cmd *cmd, t_cmd *cmd_head);
bool	is_tail(t_cmd *cmd);
bool	is_builtin(t_cmd *cmd);

#endif
