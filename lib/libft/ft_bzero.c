/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:44:20 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 12:49:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Set 0 to the specified length for the given memory area.
		ARGS:
			b:		Memory address to be set to 0
			len:	Memory length to set 0
	IN:
		b:	NULL or allocated memory
		len: 0 <= len <= SIZE_T_MAX
	OUT:
		normal:
			No return value.
			b replaces the content with 0 for the length of len
			If len=0, nothing is done.
		b is NULL:
			Nothing to do.
*/

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	if (!b)
		return ;
	ft_memset(b, 0, len);
}
