/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/17 15:19:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/**
 * @brief 正しいリダイレクトかチェックします。
 * @param str
 * @return int
 * @note 現状のチェックは連続したREDIRCTをチェックしています。
 */
int	is_redirect_validate(char *str)
{
	while (*str)
	{
		if (!ft_strncmp(str, ">>>", 3))
			return (show_tokenizer_error(ERR_UNEXPECTED_TOKEN_R1), 0);
		else if (!ft_strncmp(str, "<<<", 3))
			return (show_tokenizer_error(ERR_UNEXPECTED_TOKEN_L1), 0);
		if (*str == '>')
		{
			if(*(str + 1) == '<')
				return (show_tokenizer_error(ERR_UNEXPECTED_TOKEN_L1), 0);
		}
		if (*str == '<')
		{
			if(*(str + 1) == '>')
				return (show_tokenizer_error(ERR_UNEXPECTED_TOKEN_R1), 0);
		}
		str++;
	}
	return (1);
}
