/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:52:17 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/16 17:52:29 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new = 0;
	while (lst)
	{
		set = f(lst->content);
		if (!set)
			return (ft_lstclear(&new, del), NULL);
		node = ft_lstnew(set);
		if (!node)
		{
			del(set);
			return (ft_lstclear(&new, del), NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
