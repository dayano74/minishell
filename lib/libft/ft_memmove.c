/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:44:03 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/23 19:56:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief src領域をdst領域にオーバーラップを考慮したコピーを行います。
 * 
 * @param [out]	dst	: コピー先のメモリ領域
 * @param [in]	src	: コピー元のメモリ領域
 * @param [in]	len	: コピーする領域の長さ
 * @return void* 	: dstを返します
 * @note : 
 * 	dstとsrcのメモリアドレス番地の位置で挙動が変わります。
 * 	dst <  src なら前方からコピー
 *  dst == src ならdをそのまま返す（内容が同じのため）
 *  それ以外は後方コピーを行います
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (s == d)
		return (d);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
