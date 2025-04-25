/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:09:32 by dayano            #+#    #+#             */
/*   Updated: 2025/04/24 15:55:28 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	compare(char *envp, char *minish_envp)
{
	printf("=== original ===\n");
	printf("%s\n", envp);
	printf("=== minishell ===\n");
	printf("%s\n", minish_envp);
	if (strcmp(envp, minish_envp) == 0)
		printf("\x1b[32m→ match ✔︎\x1b[0m\n\n");
	else
		printf("\x1b[31m→ mismatch ✘\x1b[0m\n\n");
	printf("\n");
}

int	main(int argc, char **argv, char **envp)
{
	char		**minish_envp;
	int			i;
	t_minish	*minish;

	(void)argc;
	(void)argv;
	minish = initialize(envp);
	printf("%s\n", minish->env->value);
	printf("initialize done\n");
	minish_envp = create_envp(minish);
	printf("create_envp done\n\n");
	i = 0;
	while (envp[i] && minish_envp[i])
	{
		compare(envp[i], minish_envp[i]);
		i++;
	}
	if (envp[i] == NULL && minish_envp[i] == NULL)
		printf("\x1b[33mboth envp[%d] are NULL (end)\x1b[0m\n", i);
	else
		printf("\x1b[31menvp[%d] NULL mismatch\x1b[0m\n", i);
	return (0);
}
