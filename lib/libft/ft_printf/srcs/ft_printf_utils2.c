/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:58 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:31:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

/**
 * @brief Recursive function for ptf_putptr_fd address output
 * 
 * @param hex 
 * @param fd 
 * @return size_t 
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
 * @brief Output pointer in hexadecimal format
 * 
 * @param ptr 
 * @param fd 
 * @return size_t 
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
 * @brief Fill memory area b with letter c. 
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
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
