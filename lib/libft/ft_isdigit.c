/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:40:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 10:54:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION:
		SUMMARY:
			Find out if it is numeric.
		ARGS:
			c:	ASCII code number.
	IN:
		c:
			INT_MIN <= c <= INT_MAX
	OUT:
		c =		[0-9]	-> 1
		else			-> 0
*/

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
