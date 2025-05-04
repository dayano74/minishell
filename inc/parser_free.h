/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:22:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 21:27:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_FREE_H
# define PARSER_FREE_H

void	free_tokens(char **tokens);
void	free_cmd(t_cmd *cmd);
void	free_cmds(t_cmd **cmds);

#endif