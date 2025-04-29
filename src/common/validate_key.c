/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:43:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 11:43:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	is_key_start(int c)
{
	return (ft_isalpha(c) || c == '_');
}

bool	is_key_char(int c)
{
	return (ft_isalnum(c) || c == '_');
}

bool	is_valid_key(char *str)
{
	size_t	i;
	
	if (!str || !is_key_start(str[0]))
		return (false);
	i = 1;
	while (str[i])
		if (!is_key_char(str[i++]))
			return (false);
	return (true);
}
