/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:25:47 by dayano            #+#    #+#             */
/*   Updated: 2025/04/17 10:29:25 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "struct.h"

char	*get_env_name(const char *env_entry);
void	free_env_content(char *value);
void	remove_env_node(t_env **env_lst, t_env *target);

#endif
