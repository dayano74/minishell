/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:42:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 11:17:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief envpの構造体の値をセットします。
 *
 * @param env_val
 * @param node
 * @return 0: 失敗
 * @return 1: 成功
 */
static int	_set_envp(char *env_val, t_env *node)
{
	size_t	env_len;
	size_t	eq_pos;

	env_len = ft_strlen(env_val);
	eq_pos = ft_strlen_until(env_val, '=');
	node->key = NULL;
	node->value = NULL;
	if (eq_pos == ft_strlen(env_val))
		return (0);
	node->key = ft_substr(env_val, 0, eq_pos);
	node->value = ft_substr(env_val, eq_pos + 1, env_len - eq_pos - 1);
	if (!node->key || !node->value)
		return (0);
	node->is_exported = 1;
	return (1);
}

/**
 * @brief Create a envp list object
 *
 * @param envp
 * @return t_env*
 * @note TODO: _set_envp失敗時のメモリ開放処理が不足している。envp_list全体のメモリ開放が必要
 */
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
		if (!_set_envp(envp[i], node))
			return (free(node), NULL);
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
