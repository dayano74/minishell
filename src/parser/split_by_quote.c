/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:03:29 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/15 12:00:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_quote	_get_quote_type(char quote)
{
	if (quote == '\'')
		return (QUOTE_SINGLE);
	else if (quote == '"')
		return (QUOTE_DOUBLE);
	return (QUOTE_NONE);
}

static t_part	*_make_part(char *text, t_quote quote)
{
	t_part	*part;

	if (!text)
		return (NULL);
	part = ft_calloc(1, sizeof(t_part));
	if (!part)
		return (free_str(&text), NULL);
	part->text = text;
	part->quote = quote;
	return (part);
}

static bool	_handle_unquoted_segment(const char *s, size_t *i, t_list **parts)
{
	size_t	start;
	t_part	*part;
	char	*one;
	bool	i_eq_st;

	start = *i;
	i_eq_st = false;
	while (s[*i] && !is_quote(s[*i]))
		(*i)++;
	if (*i == start)
	{
		i_eq_st = true;
		one = ft_substr(s, *i, 1);
		if (!one)
			return (false);
		part = _make_part(one, QUOTE_NONE);
	}
	else
		part = _make_part(ft_substr(s, start, *i - start), QUOTE_NONE);
	if (!part)
		return (false);
	ft_lstadd_back(parts, ft_lstnew(part));
	if (i_eq_st)
		(*i)++;
	return (true);
}

static bool	_handle_quoted_segment(const char *s, size_t *i, t_list **parts)
{
	char	quote;
	size_t	i_st;
	t_part	*part;

	quote = s[*i];
	i_st = (*i)++;
	while (s[*i] && s[*i] != quote)
		(*i)++;
	if (!s[*i])
		return (false);
	(*i)++;
	part = _make_part(ft_substr(s, i_st, *i - i_st), _get_quote_type(quote));
	if (!part)
		return (false);
	ft_lstadd_back(parts, ft_lstnew(part));
	return (true);
}

t_list	*split_by_quote(char *token)
{
	t_list	*parts;
	size_t	i;

	parts = NULL;
	i = 0;
	while (token[i])
	{
		if (is_quote(token[i]) && has_closing_quote(token, token[i], i + 1))
		{
			if (!_handle_quoted_segment(token, &i, &parts))
				return (ft_lstclear(&parts, free), NULL);
		}
		else
		{
			if (!_handle_unquoted_segment(token, &i, &parts))
				return (ft_lstclear(&parts, free), NULL);
		}
	}
	return (parts);
}
