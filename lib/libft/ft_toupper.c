/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:38:48 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 12:13:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Change to upper case
		ARGS:
			c:	ASCII code number.
	IN:
			INT_MIN <= c <= INT_MAX
	OUT:
		c = [a-z]	-> return c - 32
		else		-> return c
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}
