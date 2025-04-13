/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:42:55 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 10:25:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		SUMMARY:
			Find out if it is alphabetical or numeric.
		ARGS:
			c:	ASCII code number.
	IN:
		c:
			INT_MIN <= c <= INT_MAX
	OUT:
		c = [A-Za-z] or [0-9]	-> 1
		else					-> 0
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
