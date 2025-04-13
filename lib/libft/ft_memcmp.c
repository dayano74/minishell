/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:36:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:04:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Compare byte strings
		ARGS:
			s1:	byte strings 1
			s2: byte strings 2
			n:	Length to compare.
	IN:
		s1:	NULL or allocated memory.
		s2:	NULL or allocated memory.
		n:	0 <= n <= SIZET_MAX
	OUT:
		normal:
			s1 and s2 are the same:
				return 0
			Differential:
				Return the difference of mismatched byte sequences
		s1 is NULL or s2 is NULL:
			Operation is not guaranteed due to undefined operation.
		s1.length < n or s2.length < n:
			Operation is not guaranteed due to undefined operation.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*_s1;
	const unsigned char	*_s2;

	i = 0;
	_s1 = (const unsigned char *)s1;
	_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (_s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}
