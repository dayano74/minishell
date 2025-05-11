/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:29:20 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/11 16:33:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	close_fd(int std_fileno, int minish_std)
{
	close(std_fileno);
	dup2(minish_std, std_fileno);
	close(minish_std);
}
