/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:09:26 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 11:59:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Remove the characters from the front and back of
		the string s1 from the set
		ARGS:
			s1: The string you want to trim
			set: Character set for trimming
	IN:
		s1:		NULL or allocated memory.
		set:	NULL or allocated memory.
	OUT:
		normal:
			Trimmed string
		Trimmed string that failed to be allocated.
			return NULL
		undifined:
			s1 is null or empty
				return empty string
			set is null or empty
				return s1
	memo:
		Reason for “ed - st + 2”:
			ed is index and +2 to reserve space for '\0'.
		If s1 is all set characters:
			st moves to the end,
			ed does not move,
			malloc becomes 0+2,
			trim_str copies “\0” using ft_strlcpy.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	ed;
	char	*trim_str;

	if (s1 == NULL || *s1 == '\0')
		return (ft_strdup(""));
	if (set == NULL || *set == '\0')
		return (ft_strdup(s1));
	st = 0;
	ed = ft_strlen((char *)s1) - 1;
	while (st <= ed && ft_strchr(set, s1[st]) != NULL)
		st++;
	while (ed >= st && ft_strchr(set, s1[ed]) != NULL)
		ed--;
	trim_str = malloc(ed - st + 2);
	if (trim_str == NULL)
		return (NULL);
	ft_strlcpy(trim_str, s1 + st, ed - st + 2);
	return (trim_str);
}
