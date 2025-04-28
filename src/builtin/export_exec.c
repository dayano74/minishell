/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:11:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/28 15:12:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	_update_value(char *key, char *value, t_minish *minish)
{
	return (EXIT_SUCCESS);
}

static int	_append_value(char *key, char *value, t_minish *minish)
{
	return (EXIT_SUCCESS);
}

static int	_add_key_value(char *key, char *value, t_minish *minish)
{
	// t_env	*node;

	// node = ft_calloc(1, sizeof(t_env));
	// if (!node)
	// 	return (EXIT_FAILURE);
	// split_key_value(arg, node->key, node->value);
	// if (!node->key || !node->value)
	// 	return (free(node->key), free(node->value), free(node), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	_add_key(char *key, t_minish *minish)
{
	// t_env	*node;

	// node = ft_calloc(1, sizeof(t_env));
	// if (!node)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	export_exec(int argc, char **argv, t_minish *minish)
{
	size_t	i;
	char	*key;
	char	*value;

	i = 1;
	while (i < argc)
	{
		split_key_value(argv[i], key, value);
		if (get_env_value(minish->env, key))
		{
			if (ft_strnstr(argv[i], "+=", ft_strlen(argv[i])))
				_append_value(key, value, minish);
			else if (ft_strchr(argv[i], '='))
				_update_value(key, value, minish);
		}
		else
		{
			if (ft_strnstr(argv[i], "+=", ft_strlen(argv[i])))
				_append_value(key, value, minish);
			else if (ft_strchr(argv[i], '='))
				_update_value(key, value, minish);
			else
				_add_key(key, minish);
		}
		free(key);
		free(value);
		i++;
	}
	return (EXIT_SUCCESS);
}
