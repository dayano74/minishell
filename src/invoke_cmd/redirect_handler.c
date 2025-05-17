/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:12:09 by dayano            #+#    #+#             */
/*   Updated: 2025/05/17 16:50:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handle_all_redirection(t_cmd *cmd, t_minish *minish)
{
	t_cmd	*redir;

	while (cmd->next && is_redirect(cmd->next))
	{
		redir = cmd->next;
		if (!redirect(redir, minish))
			pipeline_exit(EXIT_FAILURE, minish);
		cmd->next = cmd->next->next;
		free_cmd(&redir);
	}
}
