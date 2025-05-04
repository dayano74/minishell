/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 12:14:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "builtin.h"
# include "builtin_utils.h"
# include "cmd.h"
# include "create_envp.h"
# include "env_utils.h"
# include "error.h"
# include "exec_pipeline.h"
# include "execute_cmd.h"
# include "initialize.h"
# include "invoke_command.h"
# include "libft.h"
# include "minish_signal.h"
# include "parser.h"
# include "pipeline_helper.h"
# include "redirect.h"
# include "struct.h"
# include "tokenizer.h"
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sysexits.h>
# include <unistd.h>

#endif
