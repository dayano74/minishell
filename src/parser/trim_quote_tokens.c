/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quote_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:52:11 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 20:12:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	_copy_quoted_content(char *token, char *result, size_t *pt_i,
		size_t *pr_i)
{
	size_t	t_i;
	size_t	r_i;
	char	quote;

	t_i = *pt_i;
	r_i = *pr_i;
	quote = token[t_i++];
	while (token[t_i] && token[t_i] != quote)
		result[r_i++] = token[t_i++];
	if (token[t_i] == quote)
		t_i++;
	else
	{
		r_i = *pr_i;
		t_i = *pt_i;
		while (token[t_i])
			result[r_i++] = token[t_i++];
	}
	*pt_i = t_i;
	*pr_i = r_i;
}

static void	_exec(char *token, char *result, size_t *pt_i, size_t *pr_i)
{
	if (is_quote(token[*pt_i]))
		_copy_quoted_content(token, result, pt_i, pr_i);
	else
		result[(*pr_i)++] = token[(*pt_i)++];
}

static char	*_trim_quote_token(char *token)
{
	size_t	t_i;
	size_t	r_i;
	char	*result;

	if (!token)
		return (NULL);
	result = ft_calloc(ft_strlen(token) + 1, sizeof(char));
	if (!result)
		return (NULL);
	t_i = 0;
	r_i = 0;
	while (token[t_i])
		_exec(token, result, &t_i, &r_i);
	free(token);
	return (result);
}

char	**trim_quote_tokens(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
	{
		tokens[i] = _trim_quote_token(tokens[i]);
		i++;
	}
	return (tokens);
}
