/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:48:44 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 10:59:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION:
		SUMMARY:
			Find out if it is printable.
			ASCII code printable characters range from 32 to 126
		ARGS:
			c:	ASCII code number.
	IN:
		c:
			INT_MIN <= c <= INT_MAX
	OUT:
		c =	32 <= c <= 126	-> 1
		else				-> 0
*/
int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
