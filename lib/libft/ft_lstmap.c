/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:45:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 18:05:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Applies function f to the passed list and returns it as a new list.
		If necessary, del is also used to delete content.
		ARGS:
			lst: Pointer to list
			f:	 Pointer to function to be applied
	IN:
		lst: NULL or Allocated memory
		f: 	 NULL or Allocated memory 
		del: NULL or Allocated memory 
	OUT:
		normal:
			Returns as a new list with function f applied.
		node create failed:
			Deletes and releases the list being created and returns NULL.
		lst is NULL:
			return NULL
		f is NULL:
			return NULL
		del is NULL:
			return NULL
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
