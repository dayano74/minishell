/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/10 13:53:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Converts the passed string to an int.
		ARGS:
			str: String to be converted to an integer
	IN:
		str:	str consists of the following three parts
			space	: any number
			+ or -	: only 1
			0-9		: any number
	OUT:
		normal:			INT_MIN	<= int(value) <= INT_MAX
		int overflow:
			The converted value of strtol is cast to LONG_MAX
			LONG_MAX and above is (int)LONG_MAX
		int underflow:
			The converted value of strtol is cast to LONG_MIN
			LONG_MIN and above is (int)LONG_MIN
		undefined:
			str is NULL:	0
*/

#include "libft.h"
#define LMAX LONG_MAX
#define LMIN LONG_MIN

//	Find out if it is space.
//	The following characters are considered spaces in ascii code.
//		'\t':9	'\n':10	'\v':11	'\f':12	'\r':13	' ':32
static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

//	Check for overflow in the next calculations.
static int	_is_next_overflow(long int num, long int degit)
{
	return ((num > LMAX / 10) || (num == LMAX / 10 && degit > 7));
}

//	Check for underflow in the next calculations.
static int	_is_next_underflow(long int num, long int degit)
{
	return ((num < LMIN / 10) || (num == LMIN / 10 && degit < -8));
}

// base 10 only
// Unlike in practice, errno notification is not performed.
// endptr is not used because it is fixed at NULL
static long int	_strtol_base10(const char *nptr)
{
	long int	sign;
	long int	degit;
	long int	num;

	sign = 1;
	num = 0;
	while (_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		degit = *nptr - '0';
		if (_is_next_overflow(sign * num, sign * degit))
			return (LONG_MAX);
		if (_is_next_underflow(sign * num, sign * degit))
			return (LONG_MIN);
		num = num * 10 + degit;
		nptr++;
	}
	return (sign * num);
}

int	ft_atoi(const char *str)
{
	if (!str)
		return (0);
	return ((int)_strtol_base10(str));
}
