/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:47:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/01 15:30:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_export_exec_bool
{
	bool	exists;
	bool	has_plus;
	bool	has_eq;
}			t_export_exec_bool;

char		*ft_strndup(const char *s1, size_t n);
int			export_exec(int argc, char **argv, t_minish *minish);
int			print_sorted_env(t_env *head);
void		export_err_invalid(char *sh, char *arg);
int			split_key_value(char *str, char **key_out, char **val_out);

#endif