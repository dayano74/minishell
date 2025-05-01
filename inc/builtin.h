/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/01 15:48:19 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 4096

# include "builtin_utils.h"
# include "struct.h"

typedef int	(*builtin)(int argc, char *argv[], t_minish *minish);

int			builtin_echo(int argc, char *argv[], t_minish *minish);
int			builtin_pwd(int argc, char *argv[], t_minish *minish);
int			builtin_exit(int argc, char *argv[], t_minish *minish);
int			builtin_cd(int argc, char *argv[], t_minish *minish);
int			builtin_env(int argc, char **argv, t_minish *minish);
int			builtin_unset(int argc, char *argv[], t_minish *minish);
int			builtin_export(int argc, char **argv, t_minish *minish);

#endif
