/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:35:46 by dayano            #+#    #+#             */
/*   Updated: 2025/05/17 16:33:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// unset with no options
// description: delete VALUE
// use case: unset VALUE

static int	is_value(char **value, int value_count, t_env *env)
{
	int		i;

	if (!env->key)
	{
		ft_putstr_fd("Error: malformed environment entry: ", STDERR_FILENO);
		ft_putendl_fd(env->value, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < value_count)
	{
		if (ft_strcmp(value[i], env->key) == 0)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

static void	unset_values(char **value, int value_count, t_env **env_lst)
{
	t_env	*current;
	t_env	*next;

	if (!env_lst || !*env_lst)
		return ;
	current = *env_lst;
	while (current)
	{
		next = current->next;
		if (!is_value(value, value_count, current))
			remove_env_node(env_lst, current);
		current = next;
	}
}

int	builtin_unset(int argc, char *argv[], t_minish *minish)
{
	char	**values;
	int		values_count;

	if (argc < 2)
		return (EXIT_SUCCESS);
	values = &argv[1];
	values_count = argc - 1;
	unset_values(values, values_count, &minish->env);
	return (EXIT_SUCCESS);
}
