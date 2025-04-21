/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:35:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 11:24:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	_show_export(t_minish *minish)
{
	t_env	*next;
	t_env	*current;

	current = minish->env;
	while (current)
	{
		next = current->next;
		if (current->is_exported)
			printf("declare -x %s=%s\n", current->key, current->value);
		current = next;
	}
}

int	builtin_export(int argc, char *argv[], t_minish *minish)
{
	(void) argv;
	if (argc == 1)
		_show_export(minish);
	return (EXIT_SUCCESS);
}
