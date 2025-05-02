/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:08:42 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 17:52:43 by ttsubo           ###   ########.fr       */
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

/**
 * @note pre: $? in str
 */
static char	*_expand_dollar(char *str, t_minish *minish)
{
	char	*pre;
	char	*suf;
	char	*sts_str;
	char	*joined;
	char	*final;

	pre = ft_substr(str, 0, ft_strlen_until(str, '$'));
	sts_str = ft_itoa(minish->last_status);
	suf = ft_strdup(str + ft_strlen_until(str, '$') + 2);
	if (!pre || !sts_str || !suf)
		return (free(pre), free(sts_str), free(suf), NULL);
	joined = ft_strjoin(pre, sts_str);
	final = ft_strjoin(joined, suf);
	return (free(pre), free(sts_str), free(suf), free(joined), final);
}

static char	*_expand(char *token, t_minish *minish)
{
	char	*result;
	char	*tmp;

	result = ft_strdup(token);
	if (!result)
		return (NULL);
	while (ft_strchr(result, '$'))
	{
		tmp = result;
		if (ft_strnstr(result, "$?", ft_strlen(result)))
			result = _expand_dollar(tmp, minish);
		else
			result = expand_env(tmp, minish);
		free(tmp);
		if (!result)
			return (NULL);
	}
	return (result);
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
		expanded[token_i] = _expand(tokens[token_i], minish);
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
