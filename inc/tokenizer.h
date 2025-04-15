/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:36:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 15:25:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include <stdio.h>

# define ERR_UNEXPECTED_STR "An unexpected error occureed.\n"
# define ERR_SQUOTE_NOT_CLOSED_STR "unexpected EOF while looking for matching `''\n"
# define ERR_DQUOTE_NOT_CLOSED_STR "unexpected EOF while looking for matching `\"'\n"

typedef enum e_tokenizer_errors
{
	ERR_UNEXPECTED,
	ERR_SQUOTE_NOT_CLOSED,
	ERR_DQUOTE_NOT_CLOSED,
	NO_ERR,
}		t_tokenizer_errors;

void	show_tokenizer_error(t_tokenizer_errors err_code);
size_t	get_token_capa(char *str);
int		is_quote_closed(char *str);
char	**tokenizer(char *str);

#endif