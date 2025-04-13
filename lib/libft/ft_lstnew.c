/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:05:43 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/11 13:12:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Create a new node.
		ARGS:
			contents: Contents to be registered in the node
	IN:
		content: NULL or Allocated memory
	OUT:
		normal:
			Registers the contents into the allocated t_list->contents 
			and returns a pointer to that node.
		malloc failed:
			return NULL
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
