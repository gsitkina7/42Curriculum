/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:03:13 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/13 00:22:22 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst && del)
	{
		while (*lst)
		{
			temp = *lst;
			del(temp->content);
			*lst = temp->next;
			free(temp);
		}
	}
	*lst = NULL;
}
