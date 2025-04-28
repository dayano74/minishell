/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:54:35 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:14:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill memory area b with letter c. 
 *
 * @param [out]	b	: memory area
 * @param [in]	c	: fill letter
 * @param [in]	len	: length
 * @retval void*	: return b;
 * @retval NULL		: If b is NULL.
 * @note : 
 * This function internally casts int c to uchar.
 * Therefore, upper bits outside the range 0-255 are ignored in its operation.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	if (!b)
		return (b);
	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}
