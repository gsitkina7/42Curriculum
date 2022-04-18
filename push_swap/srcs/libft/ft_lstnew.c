/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:30:10 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/04 10:43:56 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (temp)
	{
		temp->num = content;
		temp->next = NULL;
	}
	return (temp);
}
