/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:48:02 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 20:06:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Apply function f to string s one character at a time
		ARGS:
			s:	string.
			f:	Pointer to function to be applied
	IN:
		s:	NULL or allocated memory.
		f:	NULL or allocated memory.
	OUT:
		No return value
		s is changed by f.
		s or f is NULL
			Nothing to do;
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
