/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_capa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 16:03:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/**
 * @brief 文字列配列のキャパシティを計算します。
 * 
 * @param str 
 * @return size_t
 * @note 空白・リダイレクト・パイプの個数を求めています。
 */
size_t	get_token_capa(char *str)
{
	size_t	capa;
	int		in_squote;
	int		in_dquote;

	capa = 1;
	in_squote = 0;
	in_dquote = 0;
	while (*str)
	{
		if (*str == '\'' && !in_dquote)
			in_squote = !in_squote;
		else if (*str == '"' && !in_squote)
			in_dquote = !in_dquote;
		if (!in_squote && !in_dquote)
		{
			if (ft_isspace(*str) || *str == '|')
				capa++;
			else if (*str == '<' || *str == '>')
			{
				capa++;
				if (*(str + 1) == *str)
					str++;
			}
		}
		str++;
	}
	return (capa);
}