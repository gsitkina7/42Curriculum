/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:19:35 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/13 00:25:04 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_new_elem(t_list *lst, void (*del)(void *), \
				void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!f || !del)
		return (NULL);
	temp = create_new_elem(lst, del, (*f)(lst->content));
	if (!temp)
		return (NULL);
	list = temp;
	lst = lst->next;
	while (lst)
	{
		temp = create_new_elem(lst, del, (*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, temp);
		lst = lst->next;
	}
	return (list);
}
