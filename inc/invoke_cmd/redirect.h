/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:20:03 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 19:19:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "common.h"

void	redirect(t_cmd *cmd);
void	redirect_stdout(t_cmd *cmd);
void	redirect_stdin(t_cmd *cmd);

#endif
