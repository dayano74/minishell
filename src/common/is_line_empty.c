/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:12:55 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/16 11:25:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (true);
	while (ft_isspace(line[i]))
		i++;
	return (line[i] == '\0');
}
