/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:35:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/15 22:03:23 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// unset with no options
// description: delete VALUE
// use case: unset VALUE

static void	_error_mes(char *name, char *mes)
{
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(mes, STDERR_FILENO);
}

static char	*get_env_name(const char *env_entry)
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

static int	is_value(char **value, int value_count, t_env *env)
{
	char	*env_name;
	int		i;

	env_name = get_env_name(env->value);
	if (!env_name)
	{
		ft_putstr_fd("Error: malformed environment entry: ", STDERR_FILENO);
		ft_putendl_fd(env->value, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < value_count)
	{
		if (ft_strcmp(value[i], env_name) == 0)
		{
			free(env_name);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(env_name);
	return (EXIT_FAILURE);
}

static void	free_env_content(char *value)
{
	free(value);
}

static void	remove_env_node(t_env **env_lst, t_env *target)
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
	{
		_error_mes(argv[0], ": wrong argument\n");
		return (EXIT_FAILURE);
	}
	values = &argv[1];
	values_count = argc - 1;
	unset_values(values, values_count, &minish->env);
	return (EXIT_SUCCESS);
}
