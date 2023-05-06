/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:37:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/05/06 12:07:19 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Iterates the list `lst` and applies the function `f` on the content
** of each node. Creates a new list resulting of the successive applications
** of the function `f`. The `del` function is used to delete the content of
** a node if needed.
**
** lst:	The address of a pointer to a node.
** f:	The address of the function used to iterate on the list.
** del:	The address of the function used to delete the content of a node.
**
** Returns:
** The new list.
** NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
