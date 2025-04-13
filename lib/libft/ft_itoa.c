/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:50:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/16 19:00:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Converts a given integer to a string
		ARGS:
			n: Integer to be converted to string
	IN:
		n:	INT_MIN <= n <= INT_MAX
	OUT:
		normal:
			Returns an integer converted to a string
		memory allocation failure:
			return NULL
		
*/

#include "libft.h"

// Return the number of digits 
static size_t	_count_digits(int n)
{
	int	count;

	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = _count_digits(n) + (n < 0);
	s = ft_calloc((len + 1) * sizeof(char), 1);
	if (!s)
		return (NULL);
	if (n < 0)
		num = -n;
	while (num > 0)
	{
		s[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
