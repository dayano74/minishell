/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:17:22 by dayano            #+#    #+#             */
/*   Updated: 2025/05/15 15:22:35 by ttsubo           ###   ########.fr       */
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
	ft_putstr_fd((char *)func_name, STDERR_FILENO);
	ft_putendl_fd(":error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
