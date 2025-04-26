/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:25:47 by dayano            #+#    #+#             */
/*   Updated: 2025/04/26 10:19:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "struct.h"

char	*get_env_value(t_env *current, const char *key);
void	free_env_content(char *value);
void	remove_env_node(t_env **env_lst, t_env *target);

#endif
