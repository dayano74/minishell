/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:11:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/08 18:19:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	_update_value(char *key, char *value, t_minish *minish)
{
	t_env	*node;

	if (!is_valid_key(key))
		return (export_err_invalid("minish", key, value));
	node = get_env_node(minish->env, key);
	if (!node)
		return (EXIT_FAILURE);
	if (node->value)
		free(node->value);
	node->value = ft_strdup(value);
	node->is_exported = 1;
	return (EXIT_SUCCESS);
}

static int	_append_value(char *key, char *value, t_minish *minish)
{
	t_env	*node;
	char	*join_str;

	if (!is_valid_key(key))
		return (export_err_invalid("minish", key, value));
	node = get_env_node(minish->env, key);
	join_str = NULL;
	if (!node)
		return (EXIT_FAILURE);
	if (node->value)
		join_str = ft_strjoin(node->value, value);
	else
		join_str = ft_strdup(value);
	if (!join_str)
		return (EXIT_FAILURE);
	free(node->value);
	node->value = join_str;
	node->is_exported = 1;
	return (EXIT_SUCCESS);
}

static int	_add_key_value(char *key, char *value, t_minish *minish)
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
	add_env_back(&minish->env, node);
	return (EXIT_SUCCESS);
}

static int	_add_key(char *key, t_minish *minish)
{
	t_env	*node;

	if (!is_valid_key(key))
		return (export_err_invalid("minish", key, NULL));
	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		return (EXIT_FAILURE);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), EXIT_FAILURE);
	node->value = NULL;
	node->is_exported = 0;
	add_env_back(&minish->env, node);
	return (EXIT_SUCCESS);
}

int	select_export_exec(t_export_exec_vars vars, t_minish *minish)
{
	if (vars.exists && vars.has_plus)
		vars.exit_sts = _append_value(vars.key, vars.value, minish);
	else if (vars.exists && !vars.has_plus && vars.has_eq)
		vars.exit_sts = _update_value(vars.key, vars.value, minish);
	else if (!vars.exists && (vars.has_plus || vars.has_eq))
		vars.exit_sts = _add_key_value(vars.key, vars.value, minish);
	else if (!vars.exists)
		vars.exit_sts = _add_key(vars.key, minish);
	return (vars.exit_sts);
}
