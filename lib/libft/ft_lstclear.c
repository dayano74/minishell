/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:25:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 16:30:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		The functions 'del' and free(3) are used to delete
		and free a given node and all successor nodes of the node.
		Finally, set the pointer to the list to NULL.
		ARGS:
			lst: Address of the node to be deleted.
			del: function pointer for content deletion
	IN:
		lst: NULL or Allocated memory
		del: NULL or Allocated memory 
	OUT:
		No return value.
		The contents of lst changes as follows depending on the conditions.
		normal:
			lst and subsequent nodes are deleted.
			After deletion, lst is set to NULL.
		lst is NULL:
			Nothing to do.
		del is NULL:
			Nothing to do.
			
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	*lst = NULL;
}
