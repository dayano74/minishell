/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:35:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 12:38:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	_export_key_value(char *kv, t_minish *minish)
{
	t_env	*node;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (EXIT_FAILURE);
	if (split_key_value(kv, &node->key, &node->value))
	{
		node->is_exported = 1;
	}
	else
	{
		node->key = kv;
		node->value = NULL;
		node->is_exported = 0;
	}
	add_env_back(&minish->env, node);
	return (EXIT_SUCCESS);
}

int	builtin_export(int argc, char *argv[], t_minish *minish)
{
	if (argc == 1)
		return (print_sorted_env(minish->env));
	if (argc == 2)
		return (_export_key_value(argv[1], minish));
	return (EXIT_SUCCESS);
}
