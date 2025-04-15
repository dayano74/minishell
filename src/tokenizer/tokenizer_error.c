/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:12:29 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 15:24:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	show_tokenizer_error(t_tokenizer_errors err_code)
{
	static char *err_str[] = {
		ERR_UNEXPECTED_STR,
		ERR_SQUOTE_NOT_CLOSED_STR,
		ERR_DQUOTE_NOT_CLOSED_STR,
	};

	if(0 <= err_code && err_code < NO_ERR)
		(err_str[err_code]);
	else
		printf(err_str[ERR_UNEXPECTED]);
}
