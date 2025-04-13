/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:58 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/24 10:58:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/**
 * @brief fdに文字cを出力します
 *
 * @param c			: 文字
 * @param fd 		: ファイルディスクリプタ
 * @return size_t	: 文字の長さ(おおよそ1)
 */
size_t	ptf_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * @brief 文字列sをfdに出力します
 *
 * @param s 		: 文字列
 * @param fd 		: ファイルディスクリプタ
 * @return size_t	: 文字列の長さ
 */
size_t	ptf_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*s)
		len += ptf_putchar_fd(*s++, fd);
	return (len);
}

/**
 * @brief 符号ありの数字numをfdに出力します
 *
 * @param num 		: 符号あり整数
 * @param fd 		: ファイルディスクリプタ
 * @return size_t	: 符号なし数値の長さ
 */
size_t	ptf_putnum_fd(int n, int fd)
{
	char			c;
	size_t			len;
	unsigned int	abs_num;

	len = 0;
	if (n < 0)
	{
		len += ptf_putchar_fd('-', fd);
		abs_num = (unsigned int)(-n);
	}
	else
		abs_num = (unsigned int)n;
	if (abs_num >= DEC_BASE)
		len += ptf_putunum_fd(abs_num / DEC_BASE, fd);
	c = (abs_num % DEC_BASE) + '0';
	if (ptf_putchar_fd(c, fd) == 1)
		len++;
	return (len);
}

/**
 * @brief 符号なしの数字unumをfdに出力します
 *
 * @param unum 		: 符号なし数値
 * @param fd 		: ファイルディスクリプタ
 * @return size_t	: 符号なし数値の長さ
 */
size_t	ptf_putunum_fd(unsigned int n, int fd)
{
	char	c;
	size_t	len;

	len = 0;
	if (n >= DEC_BASE)
		len += ptf_putunum_fd(n / DEC_BASE, fd);
	c = (n % DEC_BASE) + '0';
	if (ptf_putchar_fd(c, fd) == 1)
		len++;
	return (len);
}

/**
 * @brief 符号なし整数を１６進数形式の文字列で出力します
 *
 * @param num		: 変換する符号なし整数
 * @param fd 		: ファイルディスクリプタ
 * @param is_upper	: 大文字表記にするかのフラグ(1だと有効)
 * @return char*	: 変換後の文字列の先頭ポインタ
 * @note			: pre: 負の数は呼び出し元で変換すること
 */
size_t	ptf_puthex_fd(unsigned int n, int fd, int is_upper)
{
	char	c;
	size_t	len;

	len = 0;
	if (n >= HEX_BASE)
		len += ptf_puthex_fd(n / HEX_BASE, fd, is_upper);
	if (is_upper)
		c = UPPER_HEX[n % HEX_BASE];
	else
		c = LOWER_HEX[n % HEX_BASE];
	if (ptf_putchar_fd(c, fd) == 1)
		len++;
	return (len);
}
