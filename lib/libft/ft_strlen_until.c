/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:38:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:16:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the length of string s up to character stop. 
 *
 * @param s
 * @param stop
 * @return size_t
 * @note If stop not found, return s length.
 */
size_t	ft_strlen_until(const char *s, char stop)
{
	const char	*pos = ft_strchr(s, stop);

	if (pos)
		return ((size_t)(pos - s));
	else
		return (ft_strlen(s));
}
