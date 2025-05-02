/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 17:19:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cmd.h"
# include "expand_env.h"
# include "libft.h"

size_t	count_cmds(char **tokens);
char	**next_cmd_start(char **token_ptr);
t_cmd	**calloc_cmds(char **tokens);
t_cmd	*calloc_cmd(void);
char	**calloc_argv(char **tokens);
char	*calloc_arg(char *token);

t_cmd	**parser(char **tokens, t_minish *minish);
char	**expand_tokens(char **tokens, t_minish *minish);
void	set_cmd_type(t_cmd *cmd, char *token);
size_t	cmds_len(t_cmd **cmds);
size_t	count_args_until_separator(char **tokens);
int		is_separator(char *token);
void	free_cmds(t_cmd **cmds, size_t count);
t_cmd	**allocate_cmds(char **tokens);
t_cmd	**setup_cmds(t_cmd **cmds, char **tokens, t_minish *minish);

#endif