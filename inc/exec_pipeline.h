/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:12:27 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 11:48:05 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPELINE_H
# define EXEC_PIPELINE_H

# include "cmd.h"
# include <sys/types.h>
# include <sys/wait.h>

void	exec_pipeline(t_cmd *cmd_head, t_minish *minish);
int		wait_pipeline(t_cmd *cmd_head);

#endif
