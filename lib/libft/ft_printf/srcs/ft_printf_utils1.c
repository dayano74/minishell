/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:58 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:28:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/**
 * @brief Outputs the letter c to fd.
 *
 * @param c			: char
 * @param fd 		: file descriptor
 * @return size_t	: char length.(approximately 1)
 */
size_t	ptf_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * @brief Outputs the string s to fd.
 *
 * @param s 		: string
 * @param fd 		: file descriptor
 * @return size_t	: string length
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
 * @brief Outputs the signed n num to fd.
 *
 * @param num 		: int
 * @param fd 		: file descriptor
 * @return size_t	: n length
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
 * @brief Output unsigned number n to fd.
 *
 * @param n 		: ungigned number
 * @param fd 		: file descriptor
 * @return size_t	: n length
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
 * @brief Output unsigned integer as string in hexadecimal format.
 *
 * @param num		: Unsigned integer to convert
 * @param fd 		: file descriptor
 * @param is_upper	: Flag for capitalization (1 means valid)
 * @return char*	: First pointer of converted string
 * @note			: pre: Negative numbers must be converted at the caller
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
