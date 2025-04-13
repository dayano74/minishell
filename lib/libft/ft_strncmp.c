/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:02:48 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 20:40:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Compare strings up to n characters
		ARGS:
			s1:	string1
			s2:	string2
			n:	Length to compare
	IN:
		s1:	NULL or allocated memory.
		s2:	NULL or allocated memory.
		n:	0 <= n <= SIZE_T_MAX
	OUT:
		normal:
			s1 and s2 are the same up to n characters:
				return 0
			Differential:
				Return the difference of mismatched byte sequences
		s1 or s2 is NULL
			Operation is not guaranteed due to undefined operation.
		
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
