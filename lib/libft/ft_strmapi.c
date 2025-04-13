/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:21:04 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 20:36:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Applies function f to a string one character at a time.
		The applied string is stored in a separate memory area and returned.
		ARGS:
			s:	string
			f:	function pointer.
	IN:
		s:	NULL or allocated memory.
		f:	NULL or allocated memory.
	OUT:
		normal:	
			Returns the address of the new string
			to which function f is applied.		
		Failed to allocate memory for new string:
			return NULL
		s or f is NULL
			return NULL
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_s;

	if (s == NULL || f == NULL)
		return (NULL);
	new_s = ft_strdup(s);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
