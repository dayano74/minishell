/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:42:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/17 12:01:48 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		node->value = ft_strdup(envp[i]);
		if (!node->value)
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
