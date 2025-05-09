/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:11:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/08 18:20:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	export_exec(int argc, char **argv, t_minish *minish)
{
	t_export_exec_vars	vars;

	vars.i = 1;
	vars.last_exit_sts = 0;
	while (vars.i < argc)
	{
		split_key_value(argv[vars.i], &vars.key, &vars.value);
		vars.exists = has_env_key(minish->env, vars.key);
		vars.has_plus = ft_strnstr(argv[vars.i], "+=",
				ft_strlen(argv[vars.i])) != NULL;
		vars.has_eq = ft_strchr(argv[vars.i], '=') != NULL;
		vars.exit_sts = select_export_exec(vars, minish);
		free_str(&vars.key);
		free_str(&vars.value);
		if (vars.exit_sts)
			vars.last_exit_sts = vars.exit_sts;
		vars.i++;
	}
	return (vars.last_exit_sts);
}
