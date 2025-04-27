/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:03:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

/**
 * @brief Checks if the redirect symbol is a valid value.
 * @param str
 * @return int
 * @note For now, this function only checks for consecutive redirect symbols.
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
			if (*(str + 1) == '<')
				return (show_tokenizer_error(ERR_UNEXPECTED_TOKEN_L1), 0);
		}
		if (*str == '<')
		{
			if (*(str + 1) == '>')
				return (show_tokenizer_error(ERR_UNEXPECTED_TOKEN_R1), 0);
		}
		str++;
	}
	return (1);
}
