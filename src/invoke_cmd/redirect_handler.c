/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:12:09 by dayano            #+#    #+#             */
/*   Updated: 2025/05/15 21:23:22 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void handle_all_redirection(t_cmd *cmd, t_minish *minish)
{
	t_cmd *redir;

	while(cmd->next && is_redirect(cmd->next))
	{
		redir = cmd->next;
		if(!redirect(redir))
			pipeline_exit(EXIT_FAILURE, minish);
		cmd->next = cmd->next->next;
		free_cmd(&redir);
	}
}
