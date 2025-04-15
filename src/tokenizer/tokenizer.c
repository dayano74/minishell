/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:35:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 14:00:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/**
 * @brief 生文字を意味のある単語単位で切り分けます。
 *
 * @param str
 * @return char**
 */
char	**tokenizer(char *str)
{
	int i;
	char **tokens;

	tokens = ft_calloc(_get_token_capa(str), sizeof(char *));
	if (!tokens)
		return (NULL);
	i = 0;
	while (str[i])
	{
		i++;
	}
}