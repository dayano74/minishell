/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:10:22 by dayano            #+#    #+#             */
/*   Updated: 2025/05/08 16:53:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/wait.h>

typedef enum e_read_result
{
	READ_EOF,
	READ_EMPTY,
	READ_OK
}					t_read_result;

typedef enum e_redir_type
{
	REDIR_NONE,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	REDIR_HEREDOC
}					t_redir_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				is_exported;
	struct s_env	*next;
}					t_env;

typedef struct s_minish
{
	t_env			*env;
	int				last_status;
}					t_minish;

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
