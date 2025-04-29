/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 12:17:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cmd.h"
# include "libft.h"
# include "expand_env.h"

t_cmd	**parser(char **tokens, t_minish *minish);
void	set_cmd_type(t_cmd *cmd, char *token);
size_t	cmds_len(t_cmd **cmds);
int		is_separator(char *token);
void	free_cmds(t_cmd **cmds, size_t count);
t_cmd	**allocate_cmds(char **tokens);
t_cmd	**setup_cmds(t_cmd **cmds, char **tokens, t_minish *minish);

#endif