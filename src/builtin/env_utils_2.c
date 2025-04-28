/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:17:22 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 16:32:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_env_list(t_env *head)
{
	t_env	*next;

	while (head)
	{
		next = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = next;
	}
}

void	cleanup_minish(t_minish *minish)
{
	if (!minish)
		return ;
	free_env_list(minish->env);
	free(minish);
}

void	handle_error_and_exit(const char *func_name, t_minish *minish)
{
	cleanup_minish(minish);
	perror(func_name);
	exit(EXIT_FAILURE);
}

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
		*val_out = ft_substr(str, val_start, ft_strlen(str) - val_start);
		if (!*val_out)
			return (free(*key_out), *key_out = NULL, 1);
	}
	return (0);
}
