/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:54:35 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/23 19:38:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief メモリ領域bを文字cで穴埋めします
 *
 * @param [out]	b	: メモリ領域
 * @param [in]	c	: 穴埋めする文字
 * @param [in]	len	: 穴埋めする長さ
 * @retval void*	: 穴埋めしたメモリ領域
 * @retval NULL		: bがNULLの場合
 * @note : 
 * 内部でuchar型にキャストするので、
 * 0-255の範囲外の数字は上位ビットが無視された値で使われます。
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
