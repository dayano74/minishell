/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:08:42 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 13:08:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	_free_part(void *ptr)
{
	t_part	*part;

	part = ptr;
	if (!part)
		return ;
	free(part->text);
	free(part);
}

static size_t	_tokens_len(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

char	*expand_token(char *token, t_minish *minish)
{
	t_list	*parts;
	char	*result;

	parts = split_by_quote(token);
	if (!parts)
		return (NULL);
	result = join_expanded_parts(parts, minish);
	ft_lstclear(parts, _free_part);
	return (result);
}

char	**expand_tokens(char **tokens, t_minish *minish)
{
	size_t	i;
	size_t	count;
	char	**result;

	count = _tokens_len(tokens);
	result = ft_calloc(sizeof(char *), count + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = expand_token(tokens[i], minish);
		printf("DBG:expand: '%s' → '%s'\n", tokens[i], result[i]);
		if (!result[i])
			return (free_strs(&result), NULL);
		i++;
	}
	return (result);
}
