/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:17:22 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 13:53:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_env_back(t_env **lst, t_env *new)
{
	t_env	*node;

	if (*lst != NULL)
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*lst = new;
}

/**
 * @brief Get the env node object
 * 
 * @param current 
 * @param key 
 * @return t_env* 
 * @return NULL: if the key is not found or the key is NULL
 */
t_env	*get_env_node(t_env *current, const char *key)
{
	if (!current || !key)
		return (NULL);
	while (current)
	{
		if (!ft_strcmp(current->key, key))
			return (current);
		current = current->next;
	}
	return (NULL);
}

/**
 * @brief Get the env value
 *
 * @param lst
 * @param key
 * @return char*
 * @return NULL: if the key is not found or the key is NULL
 */
char	*get_env_value(t_env *current, const char *key)
{
	if (!current || !key)
		return (NULL);
	while (current)
	{
		if (!ft_strcmp(current->key, key))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

bool	has_env_key(t_env *current, const char *key)
{
	if (!current || !key)
		return (false);
	while (current)
	{
		if (!ft_strcmp(current->key, key))
			return (true);
		current = current->next;
	}
	return (false);
}
