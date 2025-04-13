/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:56:11 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 17:52:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Add node 'new' to the top of the list.
		ARGS:
			lst: pointer address to the first link in the list
			new: pointer address to the node to be added to the list
	IN:
		lst:	NULL or Allocated memory
		new:	NULL or Allocated memory	
	OUT:
		normal:
			No return value
			Add new to the top of lst.
		lst is NULL:
			make lst with new at the top.
		new is NULL:
			Nothing to do.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
