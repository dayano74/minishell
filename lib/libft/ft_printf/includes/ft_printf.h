/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:04:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 21:08:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "format_handler.h"
# include "ft_printf_utils.h"
# include "ft_printf_define.h"
# include <stdarg.h>

typedef int	(*t_handler)(va_list *args);

int	ft_printf(const char *str, ...);

#endif