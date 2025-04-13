/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:26:29 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:14:51 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Copies the byte sequence src to the allocated dst up to length len.
		ARGS:
			dst: Area to hold the copied byte sequence
			src: Byte sequence to be copied
			len: Length to copy
	IN:
		dst:	NULL or allocated memory.
		src:	NULL or allocated memory.
		len:	0 <= len <= SIZE_T_MAX
	OUT:
		normal:
			Returns the top address of dst whose src has already been copied.
			If len is 0, nothing is copied.
		dst is NULL or src is NULL:
			Operation is not guaranteed due to undefined operation.
		dst.length < n or src.length < n:
			Operation is not guaranteed due to undefined operation.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (len--)
		*d++ = *s++;
	return (dst);
}
