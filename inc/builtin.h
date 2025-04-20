/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/20 19:48:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 4096

# include "struct.h"
# include "builtin_utils.h"

int	builtin_echo(int argc, char *argv[]);
int	builtin_pwd(int argc, char *argv[]);
int	builtin_exit(int argc, char *argv[]);
int	builtin_cd(int argc, char *argv[]);
int	builtin_env(int argc, char **argv, t_minish *minish);
int	builtin_unset(int argc, char *argv[], t_minish *minish);

#endif
