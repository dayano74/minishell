/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:28:42 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 13:51:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Searches for the passed memory with c and returns its location.
		However, the length of the search is limited to n.
		ARGS:
			s:	Memory to be searched
			c:	Characters to search for (passed as ASCII digits)
			n:	Length to search
	IN:
		s:	NULL or allocated memory.
		c:	INT_MIN <= c <= INT_MAX
		n:	0 <= n <= SIZET_MAX
	OUT:
		normal:
			found c:
				return c address.
			not found c:
				return NULL
		s is NULL:
			return NULL
		c is outside the ASCII range:
			It is cast to an unsigned char and only the lower 8 bits are used.
		s.length < n:
			Operation is not guaranteed due to undefined operation.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*us;

	if (s == NULL)
		return (NULL);
	i = 0;
	us = (const unsigned char *)s;
	while (i < n)
	{
		if (us[i] == (unsigned char)c)
			return ((void *)&us[i]);
		i++;
	}
	return (NULL);
}
