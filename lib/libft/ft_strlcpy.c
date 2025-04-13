/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:30:54 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 20:29:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Safely copy src to dst.
		ARGS:
			dst:
				String before attaching.
				Assuming sufficient space is available
			src:
				String to be copy
			dstsize:
				Size reserved by dst
	IN:
		dst:		NULL or allocated memory.
		src:		NULL or allocated memory.
		destsize:	0 <= dstsize <= SIZE_T_MAX	
	OUT:
		normal:
			return src length.
			and copy src to the end of dst as much as possible
		dstsie is 0:
			return src length.
			but nothing to do.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	copied;

	copied = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (copied < dstsize - 1 && *src)
	{
		*dst++ = *src++;
		copied++;
	}
	*dst = '\0';
	return (copied + ft_strlen(src));
}
