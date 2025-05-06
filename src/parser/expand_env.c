/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:15:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 14:03:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*_ft_strndup(const char *s1, size_t n)
{
	char	*d;

	if (!s1)
		return (NULL);
	d = malloc(n + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s1, n + 1);
	return (d);
}

static char	*_join_str(t_expand_temp tmp)
{
	size_t	pre_len;
	size_t	val_len;
	size_t	suff_len;
	size_t	total_len;
	char	*result;

	pre_len = ft_strlen(tmp.prefix);
	val_len = ft_strlen(tmp.value);
	suff_len = ft_strlen(tmp.suffix);
	total_len = pre_len + val_len + suff_len + 1;
	result = malloc(total_len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, tmp.prefix, total_len);
	ft_strlcat(result, tmp.value, total_len);
	ft_strlcat(result, tmp.suffix, total_len);
	return (result);
}

/**
 * @brief   expand_temp is used to release memory allocations.
 *
 * @param   tmp
 * @note    tmp->suffix is part of tkn->input, so free() is not executed.
 * @note    tmp->result is assigned to tkn->input, so free() is not executed.
 */
static void	_free_tmp(t_expand_temp *tmp)
{
	free(tmp->key);
	free(tmp->value);
	free(tmp->result);
	free(tmp->prefix);
	free(tmp->suffix);
}

static void	_set_tmpstr(t_minish *minish, const char *token, t_expand_env *ex_env,
		t_expand_temp *tmp)
{
	tmp->key = _ft_strndup(token + ex_env->key_st, ex_env->key_len);
	tmp->value = ft_strdup(get_env_value(minish->env, tmp->key));
	if (!tmp->value)
		tmp->value = ft_strdup("");
	tmp->prefix = _ft_strndup(token, ex_env->pre_len);
	tmp->suffix = ft_strdup(token + ex_env->key_st + ex_env->key_len);
	tmp->result = _join_str(*tmp);
}

static char	*_expand_one(const char *token, t_minish *minish,
		bool *has_expandable)
{
	const char		*env_ptr;
	t_expand_env	ex_env;
	t_expand_temp	tmp;
	char			*result;

	if (ft_strncmp(token, "$?", 2) == 0)
		return (ft_itoa(minish->last_status));
	env_ptr = ft_strchr(token, '$');
	if (!env_ptr)
		return (*has_expandable = false, ft_strdup(token));
	ft_bzero(&tmp, sizeof(tmp));
	ex_env.key_len = 0;
	ex_env.pre_len = env_ptr - token;
	ex_env.key_st = ex_env.pre_len + 1;
	if (!is_key_start(token[ex_env.key_st]))
		return (*has_expandable = false, ft_strdup(token));
	while (is_key_char(token[ex_env.key_st + ex_env.key_len]))
		ex_env.key_len++;
	_set_tmpstr(minish, token, &ex_env, &tmp);
	if (!tmp.result)
		return (*has_expandable = false, _free_tmp(&tmp), ft_strdup(token));
	result = ft_strdup(tmp.result);
	_free_tmp(&tmp);
	return (result);
}

char	*expand_vars(const char *token, t_minish *minish)
{
	bool has_expandable;
	char *result;
	char *next;

	result = ft_strdup(token);
	if (!result)
		return (NULL);
	has_expandable = true;
	while (has_expandable)
	{
		next = _expand_one(result, minish, &has_expandable);
		free(result);
		result = next;
	}
	return (result);
}