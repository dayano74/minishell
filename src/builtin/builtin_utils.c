/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:46:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/29 14:12:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * @brief TODO: Retrieve as utils function later
 * 
 * @param s1 
 * @param n 
 * @return char* 
 */
char	*ft_strndup(const char *s1, size_t n)
{
	char	*d;

	if (!s1)
		return (NULL);
	d = malloc(n + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s1, n + 1);
	return (d);
}
