/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:20:29 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 17:18:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Delete and free memory from lst using the function del.
		ARGS:
			lst:	Nodes to be released
			del:	function pointer for content deletion
	IN:
		lst: NULL or Allocated memory
		del: NULL or Allocated memory 
	OUT:
		No return value.
		The contents of lst changes as follows depending on the conditions.
		normal:
			The received node is deleted with del and then released with free.
		lst is NULL:
			Nothing to do.
		del is NULL:
			Nothing to do.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
