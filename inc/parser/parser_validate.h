/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:19:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/17 15:26:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_VALIDATE_H
# define PARSER_VALIDATE_H

# include "common.h"

bool	parser_validate(t_cmd	***cmds_ptr, t_minish *minish);

#endif