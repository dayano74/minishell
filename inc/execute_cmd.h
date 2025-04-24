/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:39:18 by dayano            #+#    #+#             */
/*   Updated: 2025/04/24 15:03:36 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_CMD_H
# define EXECUTE_CMD_H

# define PATH_PREFIX_LEN 5
# define EQUAL_LEN 1

void	execute_cmd(t_cmd *cmd, t_minish *minish);

// execute_cmd_helper.c
char	*join_path(char *dir, char *cmd);
char	*get_path_line(char **envp);
void	free_str_array(char **str);

#endif
