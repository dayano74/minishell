/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:36:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 16:43:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include <stdio.h>

# define ERR_UNEXPECTED_STR "unexpected error occureed.\n"
# define ERR_SQ_UNCLOSED_STR "unexpected EOF while looking for matching `''\n"
# define ERR_DQ_UNCLOSED_STR "unexpected EOF while looking for matching `\"'\n"
# define ERR_FAILED_ALLOCATE_TOKEN_STR "Failed to allocate memory for token.\n"

typedef enum e_tokenizer_errors
{
	ERR_UNEXPECTED,
	ERR_SQ_UNCLOSED,
	ERR_DQ_UNCLOSED,
	ERR_FAILED_ALLOCATE_TOKEN,
	NO_ERR,
}		t_tokenizer_errors;

typedef struct s_tokenizer
{
	char	*input;
	int		pos;
	int		in_squote;
	int		in_dquote;
}			t_tokenizer;

char	*read_token(t_tokenizer *tkn);
void	show_tokenizer_error(t_tokenizer_errors err_code);
size_t	get_token_capa(char *str);
int		is_quote_closed(char *str);
char	**tokenizer(char *str);

#endif