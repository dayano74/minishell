/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_cmds_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:19:28 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/02 16:58:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	count_cmds(char **tokens)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (tokens[i])
	{
		if (is_separator(tokens[i]))
			count++;
		i++;
	}
	return (count);
}
