/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:29:50 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 17:52:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Add node 'new' to the end of the list.
		ARGS:
			lst: pointer address to the first link in the list
			new: pointer address to the node to be added to the list
	IN:
		lst:	NULL or Allocated memory
		new:	NULL or Allocated memory	
	OUT:
		normal:
			No return value
			Add new to the end of lst.
		lst is NULL:
			make lst with new at the top.
		new:
			Adds null to subsequent but practically meaningless.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst != NULL)
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
	else
		*lst = new;
}
