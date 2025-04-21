/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:12:27 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 13:13:33 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPELINE_H
# define EXEC_PIPELINE_H

# include "cmd.h"

static void	exec_pipeline(t_cmd *cmd_head);
static int	wait_pipeline(t_cmd *cmd_head);

#endif
