/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:26:59 by dayano            #+#    #+#             */
/*   Updated: 2025/04/17 11:44:08 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_env_name(const char *env_entry)
{
	char	*eq_pos;
	char	*env_name;
	int		name_len;

	eq_pos = ft_strchr(env_entry, '=');
	if (!eq_pos)
		return (NULL);
	name_len = eq_pos - env_entry;
	env_name = ft_substr(env_entry, 0, name_len);
	return (env_name);
}

void	free_env_content(char *value)
{
	free(value);
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
		ft_lstdelone(current, free_env_content);
		return ;
	}
	while (current)
	{
		if (current == target)
		{
			prev->next = current->next;
			ft_lstdelone(current, free_env_content);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
