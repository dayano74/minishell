/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:30:54 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:18:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the number of characters in string s up to length n. 
 *
 * @param s
 * @param n
 * @return size_t
 * @note If the return value of ft_memchr is NULL, return n.
 */
size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*p = ft_memchr(s, 0, n);

	if (p)
		return (p - s);
	return (n);
}
