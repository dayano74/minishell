/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:47:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/22 12:28:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

# include "struct.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_export_exec_vars
{
	int		i;
	char	*key;
	char	*value;
	bool	exists;
	bool	has_plus;
	bool	has_eq;
	int		exit_sts;
	int		last_exit_sts;
}			t_export_exec_vars;

char		*ft_strndup(const char *s1, size_t n);
int			export_exec(int argc, char **argv, t_minish *minish);
int			select_export_exec(t_export_exec_vars vars, t_minish *minish);
int			print_sorted_env(t_env *head);
int			export_err_invalid(char *sh, char *key, char *value);
int			export_err_invalid_opt(char *sh, char c);
int			split_key_value(char *str, char **key_out, char **val_out);

#endif
