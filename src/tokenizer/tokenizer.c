/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:35:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 17:01:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	skip_spaces(t_tokenizer *tkn)
{
	while (ft_isspace(tkn->input[tkn->pos]))
		tkn->pos++;
}

/**
 * @brief 生文字を意味のある単語単位で切り分けます。
 *
 * @param str
 * @return char**
 */
char	**tokenizer(char *str)
{
	int			token_i;
	char		**tokens;
	t_tokenizer	tkn;

	tkn = (t_tokenizer){.input = str, .pos = 0, .in_squote = 0, .in_dquote = 0};
	if (!is_quote_closed(str))
		return (NULL);
	tokens = ft_calloc(get_token_capa(str), sizeof(char *));
	if (!tokens)
		return (show_tokenizer_error(ERR_FAILED_ALLOCATE_TOKEN), NULL);
	token_i = 0;
	while (tkn.input[tkn.pos])
	{
		skip_spaces(&tkn);
		if (!tkn.input[tkn.pos])
			break ;
		tokens[token_i++] = read_token(&tkn);
	}
	tokens[token_i] = NULL;
	return (tokens);
}
