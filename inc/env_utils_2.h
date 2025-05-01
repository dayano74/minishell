/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:40:36 by dayano            #+#    #+#             */
/*   Updated: 2025/05/01 15:20:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_2_H
# define ENV_UTILS_2_H

# include "struct.h"

void	free_env_list(t_env *head);
void	cleanup_minish(t_minish *minish);
void	handle_error_and_exit(const char *func_name, t_minish *minish);

#endif
