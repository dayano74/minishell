/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:40:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/24 13:41:26 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perser.h"

int	is_separator(char *token)
{
	return (!ft_strcmp(token, "|")
		|| !ft_strcmp(token, "<")
		|| !ft_strcmp(token, ">")
		|| !ft_strcmp(token, "<<")
		|| !ft_strcmp(token, ">>")
	);
}