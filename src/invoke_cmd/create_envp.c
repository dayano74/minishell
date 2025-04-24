/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:56:59 by dayano            #+#    #+#             */
/*   Updated: 2025/04/24 15:38:39 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	count_value(t_minish *minish)
{
	int		count;
	t_env	*current_env;

	count = 0;
	current_env = minish->env;
	while (current_env)
	{
		if (current_env->value)
			count++;
		current_env = current_env->next;
	}
	return (count);
}

static char	*get_envp_key_value(t_env *env)
{
	char	*result;
	int		key_len;
	int		value_len;
	int		buf_size;

	key_len = ft_strlen(env->key);
	value_len = ft_strlen(env->value);
	buf_size = key_len + EQUAL_LEN + value_len + 1;
	result = (char *)ft_calloc(buf_size, sizeof(char));
	if (!result)
		perror("ft_calloc");
	ft_strlcpy(result, env->key, buf_size);
	ft_strlcat(result, "=", buf_size);
	ft_strlcat(result, env->value, buf_size);
	if (!result)
		perror("ft_strlcat");
	return (result);
}

char	**create_envp(t_minish *minish)
{
	char	**envp;
	t_env	*env;
	int		i;
	int		count;

	count = count_value(minish);
	envp = (char **)ft_calloc(count, sizeof(char *));
	if (!envp)
		return (NULL);
	env = minish->env;
	i = 0;
	while (env)
	{
		if (env->value)
			envp[i] = get_envp_key_value(env);
		env = env->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
