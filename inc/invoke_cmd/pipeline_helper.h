/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_helper.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:32:27 by dayano            #+#    #+#             */
/*   Updated: 2025/05/09 11:33:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_HELPER_H
# define PIPELINE_HELPER_H

# include "common.h"
# include <fcntl.h>
# include <stdbool.h>

// pipeline_helper.c
bool	is_redirect(t_cmd *cmd);
bool	is_head(t_cmd *cmd, t_cmd *cmd_head);
bool	is_tail(t_cmd *cmd);
bool	is_builtin(t_cmd *cmd);

#endif
