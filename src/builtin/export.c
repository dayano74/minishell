/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:35:46 by dayano            #+#    #+#             */
/*   Updated: 2025/05/08 17:45:09 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_export(int argc, char *argv[], t_minish *minish)
{
	if (argc == 1)
		return (print_sorted_env(minish->env));
	if (argv[1][0] == '-' && argv[1][1] != '\0')
	{
		export_err_invalid_opt("minish", argv[1][1]);
		return (EXIT_EXPORT_INVALID_OPT);
	}
	if (argc >= 2)
		return (export_exec(argc, argv, minish));
	return (EXIT_SUCCESS);
}
