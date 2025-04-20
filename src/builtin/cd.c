/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/20 19:53:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	builtin_cd(int argc, char *argv[])
{
	if (argc != 2)
		return (error_mes(argv[0], "wrong argument"), EXIT_FAILURE);
	if (chdir(argv[1]) < 0)
		return (perror(argv[1]), 1);
	return (0);
}
