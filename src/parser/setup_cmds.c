/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:38:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 12:56:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	_allocate_argv(t_cmd *cmd, char **tokens)
{
	size_t	token_i;
	size_t	argc;

	token_i = 0;
	argc = 0;
	while (tokens[token_i] && !is_separator(tokens[token_i]))
	{
		token_i++;
		argc++;
	}
	cmd->argv = ft_calloc(argc + 1, sizeof(char *));
	if (!cmd->argv)
		return (1);
	return (0);
}

static char	*_expand_dollar(char *str, t_minish *minish, size_t i)
{
	char	*pre;
	char	*suf;
	char	*sts_str;
	char	*joined;
	char	*final;

	if (str[i + 1] && str[i + 1] == '?')
	{
		pre = ft_substr(str, 0, i);
		sts_str = ft_itoa(minish->last_status);
		suf = ft_strdup(str + i + 2);
		if (!pre || !sts_str || !suf)
			return (free(pre), free(sts_str), free(suf), NULL);
		joined = ft_strjoin(pre, sts_str);
		final = ft_strjoin(joined, suf);
		return (free(pre), free(sts_str), free(suf), free(joined), final);
	}
	else
		return (expand_env(str, minish));
}

static char	*_expand_arg(char *token, t_minish *minish)
{
	size_t	token_i;
	bool	is_squote;
	char	*result;
	char	*expanded;

	token_i = 0;
	is_squote = 0;
	result = ft_strdup(token);
	while (result[token_i])
	{
		if (result[token_i] == '\'')
			is_squote = !is_squote;
		if (!is_squote && result[token_i] == '$')
		{
			expanded = _expand_dollar(result, minish, token_i);
			if (!expanded)
				return (result);
			free(result);
			result = expanded;
			token_i = 0;
			continue ;
		}
		token_i++;
	}
	return (result);
}

static void	_next_cmd(t_cmd **cmds, size_t *cmd_i, size_t *arg_i, char *token)
{
	cmds[*cmd_i]->argv[*arg_i] = NULL;
	cmds[*cmd_i]->argc = *arg_i;
	(*arg_i) = 0;
	(*cmd_i)++;
	set_cmd_type(cmds[*cmd_i], token);
	_allocate_argv(cmds[*cmd_i], &token);
}

t_cmd	**setup_cmds(t_cmd **cmds, char **tokens, t_minish *minish)
{
	size_t	token_i;
	size_t	cmd_i;
	size_t	arg_i;

	token_i = 0;
	cmd_i = 0;
	arg_i = 0;
	set_cmd_type(cmds[0], tokens[token_i]);
	_allocate_argv(cmds[0], tokens);
	while (tokens[token_i])
	{
		if (is_separator(tokens[token_i]))
			_next_cmd(cmds, &cmd_i, &arg_i, tokens[token_i]);
		else
		{
			cmds[cmd_i]->argv[arg_i] = _expand_arg(tokens[token_i], minish);
			if (!cmds[cmd_i]->argv[arg_i])
				return (free_cmds(cmds, cmds_len(cmds)), NULL);
			arg_i++;
		}
		token_i++;
	}
	cmds[cmd_i]->argc = arg_i;
	cmds[++cmd_i] = NULL;
	return (cmds);
}
