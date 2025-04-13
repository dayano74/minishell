/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:12:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 13:56:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Search for character c from the end of string s
		ARGS:
			s:	string
			c:	ASCII code number.
	IN:
		s:	NULL or allocated memory.
		c:	0 <= c <= 127	(Range of ASCII)
	OUT:
		normal:
			found:
				Returns the pointer to the found character.
			not found:
				return NULL
		undifined:
			s is NULL:
				not found
		c is outside the range of ASCII codes:
			Executed after being cast to unsigned char
*/

#include "libft.h"

// Created with reference to musl.
char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s) + 1;
	c = (unsigned char)c;
	while (n--)
		if (s[n] == c)
			return ((char *)(s + n));
	return (NULL);
}
