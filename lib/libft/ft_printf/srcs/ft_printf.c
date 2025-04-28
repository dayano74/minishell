/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:24:10 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:35:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief If str is %, output format accordingly
 * 
 * @param str 
 * @param args 
 * @return int 
 */
static int	_format(const char **str, va_list *args)
{
	int				count;
	unsigned char	index;
	t_handler		handlers[MAX_HANDLER];

	count = 0;
	ftp_memset(handlers, 0, sizeof(handlers));
	handlers['c'] = handle_char;
	handlers['s'] = handle_string;
	handlers['p'] = handle_ptr;
	handlers['d'] = handle_decimal;
	handlers['i'] = handle_decimal;
	handlers['u'] = handle_unsigned;
	handlers['x'] = handle_lower_hex;
	handlers['X'] = handle_upper_hex;
	handlers['%'] = handle_percent;
	index = (unsigned char)**str;
	if (index >= MAX_HANDLER || !handlers[index])
	{
		count += ptf_putchar_fd('%', 1);
		count += ptf_putchar_fd(**str, 1);
	}
	else
		count += handlers[(unsigned char)**str](args);
	(*str)++;
	return (count);
}

/**
 * @brief Outputs str to standard output.
 * If arguments are present, they are converted to match the format.
 * 
 * @param str 
 * @param ... 
 * @return int 
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += _format((str++, &str), &args);
		else
			count += ptf_putchar_fd(*str++, 1);
	}
	va_end(args);
	return (count);
}
