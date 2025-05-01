/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:20:03 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 15:30:35 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "cmd.h"

void	redirect(t_cmd *cmd);
void	redirect_stdout(t_cmd *cmd);
void	redirect_stdin(t_cmd *cmd);

#endif
