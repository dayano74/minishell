/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:24:25 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/26 11:25:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_ENV_H
# define EXPAND_ENV_H

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

bool		is_key_start(int c);
bool		is_key_char(int c);

#endif