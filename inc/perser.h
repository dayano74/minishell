/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/24 14:12:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSER_H
# define PERSER_H

# include "cmd.h"
# include "libft.h"

int		is_separator(char *token);
t_cmd	**allocate_cmds(char **tokens);
t_cmd	**setup_cmds(t_cmd **cmds, char **tokens);

#endif