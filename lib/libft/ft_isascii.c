/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:45:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 10:53:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		SUMMARY:
			Find out if it is ASCII.
		ARGS:
			c:	ASCII code number.
	IN:
		c:
			INT_MIN <= c <= INT_MAX
	OUT:
		c = for ASCII(0~127)	-> 1
		else					-> 0
*/

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
