/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:19:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 11:40:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 4096

int	builtin_echo(int argc, char *argv[]);
int	builtin_pwd(int argc, char *argv[]);
int	builtin_exit(int argc, char *argv[]);
int	builtin_cd(int argc, char *argv[]);

#endif
