/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:35:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 16:00:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

// TODO
typedef struct s_tokenizer
{
	char	*input;
	int		pos;
	int		in_squote;
	int		in_dquote;
}			t_tokenizer;

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
	int token_i;
	int start;
	char **tokens;
	t_tokenizer tkn;

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
		start = tkn.pos;
		while (tkn.input[tkn.pos] && !ft_isspace(tkn.input[tkn.pos]))
			tkn.pos++;
		tokens[token_i++] = ft_substr(tkn.input, start, tkn.pos - start);
	}
	tokens[token_i] = NULL;
	return (tokens);
}