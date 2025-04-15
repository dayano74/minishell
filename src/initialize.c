/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:42:46 by dayano            #+#    #+#             */
/*   Updated: 2025/04/15 16:28:07 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

static t_env	*create_envp_list(char **envp)
{
	t_env	*envp_lst;
	int		i;

	envp_lst = (t_env *)ft_calloc(1, sizeof(t_env));
	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(envp_lst, envp[i]);
		i++;
	}
	return (envp_lst);
}

t_minish	*_initialize(char **envp)
{
	t_minish	*minish;

	rl_clear_history();
	minish = ft_calloc(1, sizeof(t_minish));
	minish->env = create_envp_list(envp);
	(void)envp;
	return (minish);
}
