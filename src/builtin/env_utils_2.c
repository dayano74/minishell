/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:17:22 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 12:21:26 by ttsubo           ###   ########.fr       */
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

int	split_key_value(char *str, char **key_out, char **val_out)
{
	size_t	env_len;
	size_t	eq_pos;

	env_len = ft_strlen(str);
	eq_pos = ft_strlen_until(str, '=');

	if (eq_pos == env_len)
		return (0);
	*key_out = ft_substr(str, 0, eq_pos);
	*val_out = ft_substr(str, eq_pos + 1, env_len - eq_pos - 1);
	if (!key_out || !val_out)
		return (0);
	return (1);
}
