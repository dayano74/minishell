/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:56:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 16:12:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	main(int argc, char **argv)
{
	char	**tokens;

	(void)argc;
	if (argc != 2)
		return (printf("usage: ./test_tokenizer.out <any message>"), 1);
	tokens = tokenizer(argv[1]);
	while (*tokens)
		printf("token=%s\n", *tokens++);
	return (0);
}
