/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:30:54 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/15 15:43:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 文字列sを長さnまでのsの文字数を返します。
 *
 * @param s
 * @param n
 * @return size_t
 * @note ft_memchrで見つからなかった場合、nがそのまま返されます。
 */
size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*p = ft_memchr(s, 0, n);

	if (p)
		return (p - s);
	return (n);
}
