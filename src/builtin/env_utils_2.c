/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:17:22 by dayano            #+#    #+#             */
/*   Updated: 2025/04/17 11:39:05 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_env_list(t_env *head)
{
	t_env	*next;

	while (head)
	{
		next = head->next;
		free(head->next);
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
