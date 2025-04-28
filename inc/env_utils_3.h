/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:40:36 by dayano            #+#    #+#             */
/*   Updated: 2025/04/28 15:47:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_3_H
# define ENV_UTILS_3_H

# include "struct.h"

void	add_env_back(t_env **lst, t_env *new);
t_env	*get_env_node(t_env *current, const char *key);
char	*get_env_value(t_env *current, const char *key);

#endif
