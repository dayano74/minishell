/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:44:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:10:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy the src area to the dst area considering overlap.
 * 
 * @param [out]	dst	:  
 * @param [in]	src	: 
 * @param [in]	len	: 
 * @return void* 	: return dst
 * @note : 
 * 	The behavior of this function changes with the position of dst and src.
 *  If dst < src, copy from the front.	
 *  If dst == src, returns dst as is.
 *  Otherwise, copy from behind.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (s == d)
		return (d);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
