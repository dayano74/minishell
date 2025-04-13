/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:00:38 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 20:03:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Copy s1 to the newly allocated area
		ARGS:
			s1:	String to copy
	IN:
		s:	NULL or allocated memory.
	OUT:
		normal:
			Returns the top address 
			of the memory from which the newly allocated s1 was copied
		malloc failed:
			return NULL
		s1 is NULL
			return NULL
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*d;

	if (!s1)
		return (NULL);
	l = (size_t)ft_strlen((char *)s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	return ((char *)ft_memcpy(d, s1, l + 1));
}
