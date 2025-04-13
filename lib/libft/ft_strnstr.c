/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:44:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/07 10:13:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Search for little from big up to length n.
		ARGS:
			big:	Search target string
			little:	Search word
			len:	length
	IN:
		big:	NULL or allocated memory.
		little:	NULL or allocated memory.
		len:	0 <= n <= SIZE_T_MAX
	OUT:
		normal:
			found a little inside a big
				Returns the pointer to the “big” that was hit.
			not found
				return NULL
			little is empty string
				return big
		undefined:
			big is NULL
				return NULL
			little is NULL
				Treat “little” as an empty string. -> return big
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_i;
	size_t	l_i;

	if (!little || *little == '\0')
		return ((char *)big);
	if (!big || len == 0)
		return (NULL);
	b_i = 0;
	while (big[b_i] && b_i < len)
	{
		l_i = 0;
		while (little[l_i] && big[b_i + l_i] && (b_i + l_i) < len)
		{
			if (big[b_i + l_i] != little[l_i])
				break ;
			l_i++;
		}
		if (little[l_i] == '\0')
			return ((char *)&big[b_i]);
		b_i++;
	}
	return (NULL);
}
