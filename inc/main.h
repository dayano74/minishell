/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:50:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/08 16:22:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "builtin.h"
# include "common.h"
# include "invoke_command.h"
# include "minish_signal.h"
# include "parser.h"
# include "tokenizer.h"
# include <readline/history.h>
# include <readline/readline.h>

extern volatile sig_atomic_t	g_sig_sts;

#endif
