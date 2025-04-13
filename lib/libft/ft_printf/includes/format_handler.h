/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:24:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 21:09:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HANDLER_H
# define FORMAT_HANDLER_H

# include <limits.h>
# include <stdarg.h>
# include "ft_printf_define.h"
# include "ft_printf_utils.h"

// handler 1
int	handle_char(va_list *args);
int	handle_string(va_list *args);
int	handle_decimal(va_list *args);
int	handle_unsigned(va_list *args);
int	handle_percent(va_list *args);

// handler 2
int	handle_ptr(va_list *args);
int	handle_lower_hex(va_list *args);
int	handle_upper_hex(va_list *args);

#endif
