/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:15:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 15:10:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_vars.h"
#include "parser.h"

static char	*_expand_sts(int last_status, size_t *i)
{
	*i = *i + 1;
	return (ft_itoa(last_status));
}

static char	*_expand_var(const char *token, size_t *i, t_minish *minish)
{
	size_t	len;
	char	*key;
	char	*value;

	len = 0;
	while (is_key_char(token[*i + len]))
		len++;
	key = ft_substr(token, *i, len);
	value = ft_strdup(get_env_value(minish->env, key));
	free_str(&key);
	*i += len;
	if (!value)
		return (ft_strdup(""));
	else
		return (value);
}

static char	*_expand_dollar(const char *token, size_t *i, t_minish *minish,
		bool *has_expandable)
{
	char	*tmp;

	*has_expandable = true;
	if (token[*i] == '?')
		tmp = _expand_sts(minish->last_status, i);
	else if (is_key_start(token[*i]))
		tmp = _expand_var(token, i, minish);
	else
		tmp = ft_strdup("$");
	return (tmp);
}

static char	*_expand_one(const char *token, t_minish *minish,
		bool *has_expandable)
{
	char	*result;
	char	*tmp;
	size_t	i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	*has_expandable = false;
	while (token[i])
	{
		if (token[i] == '$')
		{
			i++;
			tmp = _expand_dollar(token, &i, minish, has_expandable);
		}
		else
			tmp = ft_substr(token, i++, 1);
		if (!tmp)
			return (free_str(&result), NULL);
		result = strjoin_and_free(result, tmp);
	}
	return (result);
}

char	*expand_vars(const char *token, t_minish *minish)
{
	bool	has_expandable;
	char	*result;
	char	*next;

	result = ft_strdup(token);
	if (!result)
		return (NULL);
	has_expandable = true;
	while (has_expandable)
	{
		next = _expand_one(result, minish, &has_expandable);
		free(result);
		result = next;
	}
	return (result);
}
