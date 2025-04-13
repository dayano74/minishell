/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:38:48 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 12:13:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Change to lower case
		ARGS:
			c:	ASCII code number.
	IN:
			INT_MIN <= c <= INT_MAX
	OUT:
		c = [A-Z]	-> return c + 32
		else		-> return c
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
