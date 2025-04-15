/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:56:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/15 16:39:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**tokens;

	if (argc != 2)
		return (printf("usage: ./test_tokenizer.out <any message>"), 1);
	tokens = tokenizer(argv[1]);
	i = 0;
	while (*tokens)
		printf("token[%d]=%s\n", i++, *tokens++);
	return (0);
}
