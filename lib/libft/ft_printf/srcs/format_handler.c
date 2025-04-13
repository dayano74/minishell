/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:24:10 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/24 10:58:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list *args)
{
	return (ptf_putchar_fd((char)va_arg(*args, int), FD_STDOUT));
}

int	handle_string(va_list *args)
{
	char	*arg_str;

	arg_str = va_arg(*args, char *);
	if (arg_str == NULL)
		return (ptf_putstr_fd("(null)", FD_STDOUT));
	return (ptf_putstr_fd(arg_str, FD_STDOUT));
}

int	handle_decimal(va_list *args)
{
	return (ptf_putnum_fd(va_arg(*args, int), FD_STDOUT));
}

int	handle_unsigned(va_list *args)
{
	return (ptf_putunum_fd(va_arg(*args, unsigned int), FD_STDOUT));
}

int	handle_percent(va_list *args)
{
	(void)*args;
	return (ptf_putchar_fd('%', FD_STDOUT));
}
