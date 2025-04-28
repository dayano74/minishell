/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:15:24 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/26 11:49:30 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_key_start(int c)
{
	return (ft_isalpha(c) || c == '_');
}

bool	is_key_char(int c)
{
	return (ft_isalnum(c) || c == '_');
}
