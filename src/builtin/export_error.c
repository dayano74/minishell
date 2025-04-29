/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:11:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 14:43:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_export_err_invalid_arg(char *sh, char *arg)
{
	ft_putstr_fd(sh,STDERR_FILENO);
	ft_putstr_fd(": export: `",STDERR_FILENO);
	ft_putstr_fd(arg,STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier",STDERR_FILENO);
}
