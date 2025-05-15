/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:20:03 by dayano            #+#    #+#             */
/*   Updated: 2025/05/15 21:30:20 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "common.h"

// redirect.c
bool	redirect(t_cmd *cmd);
bool	redirect_stdout(t_cmd *cmd);
bool	redirect_stdin(t_cmd *cmd);
void	here_doc(char *limiter);

// redirect_handler.c
void	handle_all_redirection(t_cmd *cmd, t_minish *minish);

#endif
