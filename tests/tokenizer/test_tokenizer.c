/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:56:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/18 14:54:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void	_free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tokens;

	if (argc != 2)
		return (printf("usage: ./test_tokenizer.out <any message>"), 1);
	tokens = tokenizer(argv[1]);
	if (!tokens)
		return (1);
	i = 0;
	while (tokens[i])
	{
		printf("token[%d]=%s\n", i, tokens[i]);
		i++;
	}
	_free_tokens(tokens);
	return (0);
}
