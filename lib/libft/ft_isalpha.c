/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:27:37 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 10:52:22 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		SUMMARY:
			Find out if it is alphabet.
		ARGS:
			c:	ASCII code number.
	IN:
		c:
			INT_MIN <= c <= INT_MAX
	OUT:
		c = [A-Za-z]	-> 1
		else			-> 0
*/

#include "libft.h"

static int	_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

static int	_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (_islower(c) || _isupper(c));
}
