/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:26:59 by dayano            #+#    #+#             */
/*   Updated: 2025/04/26 10:19:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
