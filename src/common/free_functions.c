/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:48:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/04 18:20:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_functions.h"

void	free_str(char **pstr)
{
	if (!pstr || !*pstr)
		return ;
	free(*pstr);
	*pstr = NULL;
}

void	free_strs(char ***pstrs)
{
	int		i;
	char	**strs;

	i = 0;
	if (!pstrs || !*pstrs)
		return ;
	strs = *pstrs;
	while (strs[i])
		free_str(&strs[i++]);
	free(strs);
	*pstrs = NULL;
}

void	free_node(t_env **pnode)
{
	t_env	*node;

	if (!pnode || !*pnode)
		return ;
	node = *pnode;
	free(node->key);
	free(node->value);
	free(node);
	*pnode = NULL;
}

void	free_nodes(t_env **phead)
{
	t_env	*curr;
	t_env	*next;

	if (!phead || !*phead)
		return ;
	curr = *phead;
	while (curr)
	{
		next = curr->next;
		free_node(&curr);
		curr = next;
	}
	*phead = NULL;
}
