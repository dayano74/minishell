/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:47:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/28 16:42:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_export_exec_bool
{
	bool	exists;
	bool	has_plus;
	bool	has_eq;
}			t_export_exec_bool;

char		*ft_strndup(const char *s1, size_t n);
int	export_exec(int argc, char **argv, t_minish *minish);
void		error_mes(char *name, char *mes);
int			print_sorted_env(t_env *head);

#endif