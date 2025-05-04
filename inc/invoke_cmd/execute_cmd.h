/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:39:18 by dayano            #+#    #+#             */
/*   Updated: 2025/05/04 13:15:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_CMD_H
# define EXECUTE_CMD_H

# define PATH_PREFIX_LEN 5

# define CMD_FAILED_EXIT_STATUS 126
# define CMD_NOT_FOUND_EXIT_STATUS 127

void	execute_cmd(t_cmd *cmd, t_minish *minish);

// execute_cmd_helper.c
char	*join_path(char *dir, char *cmd);
char	*get_path_line(char **envp);
void	free_str_array(char **str);
void	print_cmd_not_found(t_cmd *cmd);

void	execute_cmd(t_cmd *cmd, t_minish *minish);

#endif
