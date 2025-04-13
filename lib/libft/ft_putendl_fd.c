/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:36:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Writes strings and newlines to file descriptors
		ARGS:
			s:	string to write
			fd:	file descriptor
	IN:
		s:	NULL or allocated memory space.
		fd:	INT_MIN <= fd <= INT_MAX
	OUT
		normal:
			No return value.
			s and newlines are written to the file specified in fd.	
		s is NULL:
			Nothing to do.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
