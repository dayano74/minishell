/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:12:29 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 16:27:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	show_tokenizer_error(t_tokenizer_errors err_code)
{
	static char	*err_str[] = {
		ERR_UNEXPECTED_STR,
		ERR_SQ_UNCLOSED_STR,
		ERR_DQ_UNCLOSED_STR,
		ERR_FAILED_ALLOCATE_TOKEN_STR,
	};

	if (0 <= err_code && err_code < NO_ERR)
		printf("%s", err_str[err_code]);
	else
		printf("%s", err_str[ERR_UNEXPECTED]);
}
