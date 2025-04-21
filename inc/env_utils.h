/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:25:47 by dayano            #+#    #+#             */
/*   Updated: 2025/04/21 12:25:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "struct.h"

void	add_env_back(t_env **lst, t_env *new);
void	free_env_content(char *value);
void	remove_env_node(t_env **env_lst, t_env *target);

#endif
