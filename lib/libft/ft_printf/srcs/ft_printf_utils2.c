/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:58 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/24 10:58:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/**
 * @brief ptf_putptr_fdのアドレス出力用の再帰関数
 *
 * @param hex 		: 16進数のアドレス
 * @param fd 		: ファイルディスクリプタ
 * @return size_t	: 出力した文字の長さ
 */
static size_t	_ptf_putptr_fd_rec(uintptr_t hex, int fd)
{
	char	c;
	size_t	len;

	len = 0;
	if (hex >= HEX_BASE)
		len += _ptf_putptr_fd_rec(hex / HEX_BASE, fd);
	c = LOWER_HEX[hex % HEX_BASE];
	if (ptf_putchar_fd(c, fd) == 1)
		len++;
	return (len);
}

/**
 * @brief ポインタを１６進数形式で出力します
 *
 * @param ptr		: アドレスを出力したいポインタ
 * @param fd		: ファイルディスクリプタ
 * @return size_t	: 出力した文字列の長さ
 */
size_t	ptf_putptr_fd(void *ptr, int fd)
{
	size_t	len;

	if (!ptr)
		return (ptf_putstr_fd("(nil)", fd));
	len = ptf_putstr_fd("0x", fd);
	len += _ptf_putptr_fd_rec((uintptr_t)ptr, fd);
	return (len);
}

/**
 * @brief メモリ領域bをcで長さlenまで埋めます
 * 
 * @param b 		: メモリ領域
 * @param c 		: 埋める形式 (0-255までの数値)
 * @param len 		: 埋める長さ
 * @return void*	: 適用後のメモリ領域の先頭アドレス
 */
void	*ftp_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}
