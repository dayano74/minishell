/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:12:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 13:51:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Searches for the passed string with c and returns its location.
		ARGS:
			s:	string to be searched
			c:	Characters to search for (passed as ASCII digits)
	IN:
		s:	NULL or allocated memory.
		c:	0 <= c <= UCHAR_MAX
	OUT:
		normal:
			found c:
				return c address.
			not found c:
				return NULL
		s is NULL:
			return NULL
		c is outside the range of ASCII codes:
			Executed after being cast to unsigned char
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
