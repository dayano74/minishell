/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:51 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 12:08:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Extract a substring from a character string s
		ARGS:
			s:		string
			start:	Starting position for extraction
			len:	Extractable size
	IN:
		s1:		NULL or allocated memory.
		start:	0 <= start <= len -1
		len:	0 <= len   <= SIZE_T_MAX
	OUT:
		normal:
			return substring (of length s or len)
		Failed to allocate memory for partial string:
			return NULL
		undifined:
			s is NULL
				return NULL
			start is greater than the actual length of s
				return ft_strdup("")
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len >= s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
