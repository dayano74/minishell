/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/25 18:16:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cmd.h"
# include "libft.h"

t_cmd	**parser(char **tokens);
size_t	cmds_len(t_cmd **cmds);
int		is_separator(char *token);
void	free_cmds(t_cmd **cmds, size_t count);
t_cmd	**allocate_cmds(char **tokens);
t_cmd	**setup_cmds(t_cmd **cmds, char **tokens);

#endif