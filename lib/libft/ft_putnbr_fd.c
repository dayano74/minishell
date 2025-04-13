/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 13:50:36 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Writes the number to the file descriptor
		ARGS:
			n: integer to write
			fd:	file descriptor
	IN:
		n:	INT_MIN <= n <= INT_MAX
		fd:	INT_MIN <= n <= INT_MAX
	OUT:
		No return value.
		n is written to the file specified in fd.

*/

#include "libft.h"

static void	_internal_swap(int i, char *buf)
{
	int		j;
	int		k;
	char	temp;

	j = 0;
	k = i - 1;
	while (j < k)
	{
		temp = buf[j];
		buf[j] = buf[k];
		buf[k] = temp;
		j++;
		k--;
	}
}

static void	_internal_itoa(int n, char *buf)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	num = n;
	sign = num;
	if (sign < 0)
		num = -num;
	if (num == 0)
		buf[i++] = '0';
	while (num > 0)
	{
		buf[i++] = num % 10 + '0';
		num /= 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	_internal_swap(i, buf);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];

	_internal_itoa(n, buf);
	ft_putstr_fd(buf, fd);
}
