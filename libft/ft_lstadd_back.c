/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:18:21 by ahertha           #+#    #+#             */
/*   Updated: 2021/10/12 23:00:55 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (*lst)
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*lst = new;
	}
}
