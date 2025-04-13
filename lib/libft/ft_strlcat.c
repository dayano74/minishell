/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 20:27:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Safely bind src to dst.
		ARGS:
			dst:
				String before attaching.
				Assuming sufficient space is available
			src:
				String to be concatenated behind
			dstsize:
				Size reserved by dst
	IN:
		dst:		NULL or allocated memory.
		src:		NULL or allocated memory.
		destsize:	0 <= dstsize <= SIZE_T_MAX	
	OUT:
		noormal:
			return src length.
			and copy src to the end of dst as much as possible
		No room in dst memory:
			return src length.
			but nothing to do.
		dst or src is null
			Operation is not guaranteed due to undefined operation.
			
*/

#include "libft.h"

// msul base.
static size_t	_strnlen(char *s, size_t n)
{
	const char	*p;

	p = ft_memchr(s, 0, n);
	if (p)
		return (p - s);
	else
		return (n);
}

// msul base.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	l = _strnlen(dst, dstsize);
	if (l == dstsize)
		return (l + ft_strlen(src));
	return (l + ft_strlcpy(dst + l, src, dstsize - l));
}
