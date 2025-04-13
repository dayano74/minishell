/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:38:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/15 15:42:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 文字stopまでの文字列sの長さを返します。
 *
 * @param s
 * @param stop
 * @return size_t
 * @note stopが見つからない場合、文字列sの長さが返されます。
 */
size_t	ft_strlen_until(const char *s, char stop)
{
	const char	*pos = ft_strchr(s, stop);

	if (pos)
		return ((size_t)(pos - s));
	else
		return (ft_strlen(s));
}
