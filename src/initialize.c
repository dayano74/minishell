/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:42:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 11:01:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_split_key_value(char *env_val, char **key_out, char **val_out)
{
	size_t	env_len;
	size_t	eq_pos;

	env_len = ft_strlen(env_val);
	eq_pos = ft_strlen_until(env_val, '=');
	*key_out = NULL;
	*val_out = NULL;
	if (eq_pos == ft_strlen(env_val))
		return ;
	*key_out = ft_substr(env_val, 0, eq_pos);
	*val_out = ft_substr(env_val, eq_pos + 1, env_len - eq_pos - 1);
}

static t_env	*create_envp_list(char **envp)
{
	t_env	*head;
	t_env	*tail;
	int		i;
	t_env	*node;

	head = NULL;
	tail = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		node = ft_calloc(1, sizeof(t_env));
		if (!node)
			return (NULL);
		_split_key_value(envp[i], &(node->key), &(node->value));
		if (!node->key || !node->value)
			return (free(node), NULL);
		node->is_exported = 1;
		node->next = NULL;
		if (!head)
			head = node;
		else
			tail->next = node;
		tail = node;
		i++;
	}
	return (head);
}

t_minish	*initialize(char **envp)
{
	t_minish	*minish;

	rl_clear_history();
	minish = ft_calloc(1, sizeof(t_minish));
	if (!minish)
		handle_error_and_exit("ft_calloc", minish);
	minish->env = create_envp_list(envp);
	if (!minish->env)
		handle_error_and_exit("create_envp_list", minish);
	return (minish);
}
