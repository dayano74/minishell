/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_key_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:27:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/01 14:54:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_set_len_and_pos(char *str, size_t *key_len, size_t *val_start)
{
	const char	*sep;

	sep = ft_strnstr(str, "+=", ft_strlen(str));
	if (sep)
	{
		*key_len = sep - str;
		*val_start = *key_len + 2;
	}
	else
	{
		sep = ft_strchr(str, '=');
		if (sep)
		{
			*key_len = sep - str;
			*val_start = *key_len + 1;
		}
		else
		{
			*key_len = ft_strlen(str);
			*val_start = 0;
		}
	}
}

static char	*_strip_quotes(char *str, size_t val_start)
{
	size_t	len;

	if (!str)
		return (NULL);
	str = str + val_start;
	len = ft_strlen(str);
	if ((str[0] == '"' && str[len - 1] == '"')
		|| (str[0] == '\'' && str[len - 1] == '\''))
		return (ft_substr(str, 1, len - 2));
	return (ft_strdup(str));
}

/**
 * @brief e.g. "ABC=DEF" -> key_out=ABC, valout=DEF
 * 
 * @param str 
 * @param key_out 
 * @param val_out 
 * @return int 
 */
int	split_key_value(char *str, char **key_out, char **val_out)
{
	size_t	key_len;
	size_t	val_start;

	if (!str || !key_out || !val_out)
		return (1);
	*key_out = NULL;
	*val_out = NULL;
	_set_len_and_pos(str, &key_len, &val_start);
	*key_out = ft_substr(str, 0, key_len);
	if (!*key_out)
		return (1);
	if (val_start > 0)
	{
		*val_out = _strip_quotes(str, val_start);
		if (!*val_out)
			return (free(*key_out), *key_out = NULL, 1);
	}
	return (0);
}
