/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:07:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 19:20:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

bool	has_closing_quote(const char *s, char quote, size_t i)
{
	while (s[i])
	{
		if (s[i] == quote)
			return (true);
		i++;
	}
	return (false);
}
