/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print_sorted_env.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:44:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/28 12:38:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	compare_keys(const t_env *a, const t_env *b)
{
	return (ft_strcmp(a->key, b->key));
}

static void	_qsort(t_env **array, size_t count)
{
	t_env	*tmp;
	size_t	i;
	size_t	j;

	if (!array || count < 2)
		return ;
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (compare_keys(array[j], array[j + 1]) > 0)
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static size_t	_count_size(t_env *head)
{
	size_t	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

static void	_show_env(t_env **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		printf("declare -x %s=\"%s\"\n", array[i]->key, array[i]->value);
		i++;
	}
}

int	print_sorted_env(t_env *head)
{
	size_t	i;
	size_t	count;
	t_env	*current;
	t_env	**array;

	count = _count_size(head);
	if (count == 0)
		return (EXIT_FAILURE);
	array = ft_calloc(count, sizeof(t_env *));
	if (!array)
		return (EXIT_FAILURE);
	current = head;
	i = 0;
	while (i < count)
	{
		array[i++] = current;
		current = current->next;
	}
	_qsort(array, count);
	_show_env(array, count);
	free(array);
	return (EXIT_SUCCESS);
}
