/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:44:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 11:48:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdbool.h>
# include <stddef.h>
# include "libft.h"

bool	is_key_start(int c);
bool	is_key_char(int c);
bool	is_valid_key(char *str);

#endif