/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:17:22 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 18:49:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	cleanup_minish(t_minish *minish)
{
	if (!minish)
		return ;
	free_nodes(&minish->env);
	free(minish);
}

void	handle_error_and_exit(const char *func_name, t_minish *minish)
{
	cleanup_minish(minish);
	perror(func_name);
	exit(EXIT_FAILURE);
}
