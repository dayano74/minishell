/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:50:02 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 20:13:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_FUNCTIONS_H
# define FREE_FUNCTIONS_H

# include "stdlib.h"
# include "struct.h"

void	free_str(char **pstr);
void	free_strs(char ***pstrs);
void	free_node(t_env **pnode);
void	free_nodes(t_env **phead);
void	free_cmd(t_cmd **pcmd);
void	free_cmds(t_cmd ***pcmds);
void	free_prompt(char ***ptokens, t_cmd ***pcmds, char **pline);

#endif