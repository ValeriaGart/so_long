/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:33:19 by ynguyen           #+#    #+#             */
/*   Updated: 2022/11/02 14:53:02 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap;
	t_list	*node;

	node = *lst;
	if (lst == NULL)
		return ;
	while (node != NULL)
	{
		del(node->content);
		swap = node;
		node = node->next;
		free(swap);
	}
	*lst = NULL;
}
