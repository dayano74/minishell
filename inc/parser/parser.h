/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:14:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 14:26:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "common.h"
# include "env_utils.h"
# include "expand_vars.h"
# include "libft.h"

typedef enum e_quote
{
	QUOTE_NONE,
	QUOTE_SINGLE,
	QUOTE_DOUBLE
}				t_quote;

typedef struct s_part
{
	char		*text;
	t_quote		quote;
}				t_part;

size_t	count_cmds(char **tokens);
char	**next_cmd_start(char **token_ptr);
t_cmd	**calloc_cmds(char **tokens);
t_cmd	*calloc_cmd(void);
char	**calloc_argv(char **tokens);
char	*calloc_arg(char *token);
char	**trim_quote_tokens(char **tokens);

t_cmd	**parser(char **tokens, t_minish *minish);
char	**expand_tokens(char **tokens, t_minish *minish);
void	set_cmd_type(t_cmd *cmd, char *token);
size_t	cmds_len(t_cmd **cmds);
size_t	count_args_until_separator(char **tokens);
int		is_separator(char *token);
t_cmd	**allocate_cmds(char **tokens);
t_cmd	**setup_cmds(t_cmd **cmds, char **tokens);
t_list	*split_by_quote(char *token);
char	*join_expanded_parts(t_list *parts, t_minish *minish);
char	*strjoin_and_free(char *s1, char *s2);

#endif