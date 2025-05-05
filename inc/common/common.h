/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:44:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/05 18:38:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "error.h"
# include "free_functions.h"
# include "initialize.h"
# include "libft.h"
# include "struct.h"
# include <stdbool.h>
# include <stddef.h>

bool	is_key_start(int c);
bool	is_key_char(int c);
bool	is_valid_key(char *str);
bool	is_quote(char c);
void	error_mes(char *name, char *mes);

#endif