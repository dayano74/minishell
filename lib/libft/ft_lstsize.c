/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:02:00 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 18:31:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Returns the length of the list
		ARGS:
			lst: Pointer to list
	IN:
		lst:	NULL or Allocated memory
	OUT:
		normal:
			Returns the length of the list	
		lst is NULL:
			return 0
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*now_node;

	if (lst == NULL)
		return (0);
	i = 1;
	now_node = lst;
	while (now_node->next != NULL)
	{
		i++;
		now_node = now_node->next;
	}
	return (i);
}
