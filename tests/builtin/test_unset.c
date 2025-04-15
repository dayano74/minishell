/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:53:38 by dayano            #+#    #+#             */
/*   Updated: 2025/04/15 18:39:37 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @param envp
 * @return int
 */
int	main(int argc, char *argv[], char **envp)
{
	t_minish	*minish;

	minish = _initialize(envp);
	builtin_unset(argc, argv, minish);
	return (0);
}
