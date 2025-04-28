/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:16:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/**
 * @brief Check if single and double quotes are closed.
 *
 * @param str
 * @return int
 */
int	is_quote_closed(char *str)
{
	int	in_squote;
	int	in_dquote;

	in_squote = 0;
	in_dquote = 0;
	while (*str)
	{
		if (*str == '\'' && !in_dquote)
			in_squote = !in_squote;
		else if (*str == '"' && !in_squote)
			in_dquote = !in_dquote;
		str++;
	}
	if (in_squote)
		show_tokenizer_error(ERR_SQ_UNCLOSED);
	if (in_dquote)
		show_tokenizer_error(ERR_DQ_UNCLOSED);
	return (!(in_squote || in_dquote));
}
