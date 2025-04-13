/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:08:18 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 17:53:11 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Returns the last node of the passed list.
		ARGS:
			lst: Pointer to list
	IN:
		lst: NULL or Allocated memory
	OUT:
		normal:
			Returns the last node of the passed list.
		lst is NULL:
			return NULL		
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*now_node;

	if (lst == NULL)
		return (NULL);
	now_node = lst;
	while (now_node->next != NULL)
		now_node = now_node->next;
	return (now_node);
}
