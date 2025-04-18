/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_capa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/17 12:58:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void	_check_quote(char c, int *in_squote, int *in_dquote)
{
	if (c == '\'' && !in_dquote)
		*in_squote = !(*in_squote);
	else if (c == '"' && !in_squote)
		*in_dquote = !(*in_dquote);
}

static t_token_type	_check_token_type(char c, int in_quote)
{
	if (in_quote)
		return (TK_WORD);
	if (ft_isspace(c))
		return (TK_SPACE);
	if (c == '|')
		return (TK_PIPE);
	if (c == '<' || c == '>')
		return (TK_REDIR);
	return (TK_WORD);
}

/**
 * @brief 文字列配列のキャパシティを計算します。
 *
 * @param str
 * @return size_t
 * @note 空白・リダイレクト・パイプの個数を求めています。
 */
size_t	get_token_capa(char *str)
{
	size_t			capa;
	int				in_squote;
	int				in_dquote;
	t_token_type	prev_token;
	t_token_type	curr_token;

	capa = 0;
	in_squote = 0;
	in_dquote = 0;
	prev_token = TK_NONE;
	while (*str)
	{
		_check_quote(*str, &in_squote, &in_dquote);
		curr_token = _check_token_type(*str, (in_squote || in_dquote));
		if ((*str == '<' || *str == '>') && *(str + 1) == *str)
			str++;
		if (curr_token != prev_token
			|| prev_token == TK_SPACE
			|| prev_token == TK_NONE)
			capa++;
		prev_token = curr_token;
		str++;
	}
	return (capa);
}
