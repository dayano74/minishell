/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:16:23 by dayano            #+#    #+#             */
/*   Updated: 2025/04/29 14:33:57 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief print error
 * format: minish: <cmd>: <error msg>
 *
 * @param cmd_or_path
 */
void	print_error(char *cmd_or_path)
{
	char	*error_msg;

	error_msg = strerror(errno);
	ft_putstr_fd("minish: ", STDERR_FILENO);
	ft_putstr_fd(cmd_or_path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
}
