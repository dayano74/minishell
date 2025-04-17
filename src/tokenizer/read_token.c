/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:33:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/17 11:37:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static char	*_read_quoted_token(t_tokenizer *tkn)
{
	char	quote;
	int		start;

	quote = tkn->input[tkn->pos++];
	start = tkn->pos;
	while (tkn->input[tkn->pos] && tkn->input[tkn->pos] != quote)
		tkn->pos++;
	return (ft_substr(tkn->input, start, tkn->pos++ - start));
}

/**
 * @brief
 *
 * @param tkn
 * @return char*
 */
char	*read_token(t_tokenizer *tkn)
{
	int		start;
	char	quote;

	if (tkn->input[tkn->pos] == '\'' || tkn->input[tkn->pos] == '"')
		return (_read_quoted_token(tkn));
	if (tkn->input)
		start = tkn->pos;
	while (tkn->input[tkn->pos] && !ft_isspace(tkn->input[tkn->pos]))
		tkn->pos++;
	return (ft_substr(tkn->input, start, tkn->pos - start));
}
