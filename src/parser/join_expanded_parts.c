/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_expanded_parts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:05:02 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/06 13:05:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*strjoin_and_free(char *s1, char *s2)
{
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = ft_strjoin(s1, s2);
	free_str(s1);
	free_str(s2);
	return (joined);
}

char	*join_expanded_parts(t_list *parts, t_minish *minish)
{
	char	*result;
	char	*tmp;
	t_part	*part;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (parts)
	{
		part = (t_part *)parts->content;
		if (part->quote == QUOTE_SINGLE)
			tmp = ft_strdup(part->text);
		else
			tmp = expand_env(part->text, minish);
		if (!tmp)
			return (free_str(result), NULL);
		result = strjoin_and_free(result, tmp);
		if (!result)
			return (NULL);
		parts = parts->next;
	}
	return (result);
}
