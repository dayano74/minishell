/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:08:42 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 17:22:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	_tokens_len(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

char	**expand_tokens(char **tokens, t_minish *minish)
{
	size_t	token_i;
	size_t	len;
	char	**expanded;

	len = _tokens_len(tokens);
	expanded = ft_calloc(sizeof(char *), len + 1);
	if (!expanded)
		return (NULL);
	token_i = 0;
	while (token_i < len)
	{
		expanded[token_i] = expand_env(tokens[token_i], minish);
		if (!expanded[token_i])
		{
			while (0 < token_i)
				free(expanded[--token_i]);
			free(expanded);
			return (NULL);
		}
		token_i++;
	}
	return (expanded);
}
