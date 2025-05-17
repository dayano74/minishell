/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:59:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/17 16:19:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void	_show_err_and_set_sts(t_tokenizer_errors err_code, t_minish *minish)
{
	show_tokenizer_error(err_code);
	minish->last_status = 2;
}

/**
 * @brief Checks if the redirect symbol is a valid value.
 * @param str
 * @return int
 * @note For now, this function only checks for consecutive redirect symbols.
 */
int	is_redirect_validate(char *str, t_minish *minish)
{
	while (*str)
	{
		if (!ft_strncmp(str, ">>>", 3) || (*str == '<' && *(str + 1) == '>'))
			return (_show_err_and_set_sts(ERR_UNEXPECTED_TOKEN_R1, minish), 0);
		if (!ft_strncmp(str, "<<<", 3) || (*str == '>' && *(str + 1) == '<'))
			return (_show_err_and_set_sts(ERR_UNEXPECTED_TOKEN_L1, minish), 0);
		str++;
	}
	return (1);
}
