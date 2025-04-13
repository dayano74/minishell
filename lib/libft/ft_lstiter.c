/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:41:27 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 18:00:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Iterate through the list 'lst', 
		applying the function 'f' to the contents of each node.
		ARGS:
			lst: Pointer to node
			f:	 Pointer to function to be applied
	IN:
		lst: NULL or Allocated memory
		f: 	 NULL or Allocated memory 
	OUT:
		No return value.
		The contents of lst changes as follows depending on the conditions.
		normal:
			The contents of each node are after the function f is applied.
		lst is NULL:
			Nothing to do.
		del is NULL:
			Nothing to do.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (!lst || !f)
		return ;
	node = lst;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
