/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:20:03 by dayano            #+#    #+#             */
/*   Updated: 2025/05/15 13:18:06 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "common.h"

bool	redirect(t_cmd *cmd);
bool	redirect_stdout(t_cmd *cmd);
bool	redirect_stdin(t_cmd *cmd);
void	here_doc(char *limiter);

#endif
