/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:35:29 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/15 15:35:31 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*iter;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew((f)(lst->content));
	iter = newlist;
	while (lst->next)
	{
		lst = lst->next;
		iter->next = ft_lstnew((f)(lst->content));
		if (iter->next == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		iter = iter->next;
	}
	iter = iter->next;
	return (newlist);
}
