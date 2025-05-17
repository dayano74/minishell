/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:25:47 by dayano            #+#    #+#             */
/*   Updated: 2025/05/17 12:40:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "struct.h"

void	free_env_content(char *value);
void	remove_env_node(t_env **env_lst, t_env *target);
void	cleanup_minish(t_minish *minish);
void	handle_error_and_exit(const char *func_name, t_minish *minish);
void	add_env_back(t_env **lst, t_env *new);
t_env	*get_env_node(t_env *current, const char *key);
char	*get_env_value(t_env *current, const char *key);
int		set_env_value(t_env *current, const char *key, char *value);
bool	has_env_key(t_env *current, const char *key);

#endif
