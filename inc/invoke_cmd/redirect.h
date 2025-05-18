/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:20:03 by dayano            #+#    #+#             */
/*   Updated: 2025/05/18 15:33:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "common.h"

// redirect.c
bool	redirect(t_cmd *cmd, t_minish *minish);
bool	redirect_stdout(t_cmd *cmd);
bool	redirect_stdin(t_cmd *cmd, t_minish *minish);
void	here_doc(t_cmd *cmd, char *limiter, t_minish *minish);

// redirect_handler.c
void	handle_all_redirection(t_cmd *cmd, t_minish *minish);

#endif
