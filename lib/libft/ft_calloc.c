/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:38:47 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/16 19:02:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Allocates memory of the size obtained by multiplying Count and size.
		After allocating the memory, initialize the memory with 0.
		ARGS:
			count:	Number of memories to be allocated
			size:	Size of memory to be allocated
	IN:
		count:	0 <= count <= SIZE_T_MAX
		size:	0 <= size  <= SIZE_T_MAX
	OUT:
		normal:
			Returns memory allocated by size multiplied by count.
		failure:
			Return NULL
		0 byte memory ex: (n,0),(0,n),(0,0)
			The C specification requires that it
			return either NULL or a valid pointer.
			This function basically returns a freeable valid pointer
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*_block;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / count)
		return (NULL);
	_block = malloc(count * size);
	if (!_block)
		return (NULL);
	ft_bzero(_block, count * size);
	return (_block);
}
