/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:47:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 16:53:33 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <unistd.h>

typedef enum e_redir_type
{
	REDIR_NONE,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	REDIR_HEREDOC
}					t_redir_type;

typedef struct s_cmd
{
	t_redir_type	type;
	int				argc;
	char			**argv;
	int				capa;
	int				status;
	pid_t			pid;
	struct s_cmd	*next;
}					t_cmd;

#endif
