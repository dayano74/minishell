/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:24:25 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 14:02:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_VARS_H
# define EXPAND_VARS_H

# include "common.h"
# include "struct.h"
# include <stdbool.h>

typedef struct s_expand_env
{
	size_t	pre_len;
	size_t	key_st;
	size_t	key_len;
}			t_expand_env;

typedef struct s_expand_temp
{
	char	*key;
	char	*value;
	char	*prefix;
	char	*suffix;
	char	*result;
}			t_expand_temp;

char		*expand_vars(const char *token, t_minish *minish);

#endif