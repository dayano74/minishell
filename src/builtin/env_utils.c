/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:26:59 by dayano            #+#    #+#             */
/*   Updated: 2025/05/22 12:29:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_env_content(char *value)
{
	free(value);
}

void	del_one_env_value(t_env *lst, void (*del)(char *))
{
	if (!lst || !del)
		return ;
	del(lst->key);
	del(lst->value);
	free(lst);
}

void	remove_env_node(t_env **env_lst, t_env *target)
{
	t_env	*current;
	t_env	*prev;

	if (!env_lst || !*env_lst || !target)
		return ;
	current = *env_lst;
	if (current == target)
	{
		*env_lst = current->next;
		del_one_env_value(current, free_env_content);
		return ;
	}
	while (current)
	{
		if (current == target)
		{
			prev->next = current->next;
			del_one_env_value(current, free_env_content);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	remove_env_value(t_env *env, char *key)
{
	t_env	*current;
	t_env	*prev;

	current = env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				env = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	add_env_value(t_env *env, char *key, char *value)
{
	t_env	*node;

	if (!is_valid_key(key))
		return (export_err_invalid("minish", key, value));
	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (EXIT_FAILURE);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), EXIT_FAILURE);
	node->value = ft_strdup(value);
	if (!node->value)
		return (free(node->key), free(node), EXIT_FAILURE);
	node->is_exported = 1;
	add_env_back(&env, node);
	return (0);
}
