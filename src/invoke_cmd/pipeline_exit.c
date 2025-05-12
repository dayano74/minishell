/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:29 by dayano            #+#    #+#             */
/*   Updated: 2025/05/12 09:55:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	pipeline_exit(unsigned int status, t_minish *minish)
{
	close_fd(STDIN_FILENO, minish->org_stdin);
	close_fd(STDOUT_FILENO, minish->org_stdout);
	exit(status);
}
