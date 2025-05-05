/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:33:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/05 13:02:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static int	_is_token_end(char c)
{
	return (ft_isspace(c) || c == '|' || c == '<' || c == '>' || c == '\0');
}

static char	*_read_op_token(t_tokenizer *tkn)
{
	char	c;

	c = tkn->input[tkn->pos];
	if ((c == '>' || c == '<') && tkn->input[tkn->pos + 1] == c)
		return (tkn->pos += 2, ft_substr(tkn->input, tkn->pos - 2, 2));
	if (c == '|' || c == '>' || c == '<')
		return (tkn->pos += 1, ft_substr(tkn->input, tkn->pos - 1, 1));
	return (NULL);
}

static char	*_read_word_token(t_tokenizer *tkn)
{
	int		start;
	char	quote;

	start = tkn->pos;
	while (!_is_token_end(tkn->input[tkn->pos]))
	{
		if (tkn->input[tkn->pos] == '\'' || tkn->input[tkn->pos] == '"')
		{
			quote = tkn->input[tkn->pos++];
			while (tkn->input[tkn->pos] && tkn->input[tkn->pos] != quote)
				tkn->pos++;
			if (tkn->input[tkn->pos] == quote)
				tkn->pos++;
		}
		else
			tkn->pos++;
	}
	return (ft_substr(tkn->input, start, tkn->pos - start));
}

/**
 * @brief
 *
 * @param tkn
 * @return char*
 */
char	*read_token(t_tokenizer *tkn)
{
	char	*op;

	op = _read_op_token(tkn);
	if (op)
		return (op);
	return (_read_word_token(tkn));
}
