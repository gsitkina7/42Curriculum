/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:56:42 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/04 15:05:03 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_element(int content)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->num = content;
	element->next = NULL;
	return (element);
}

void	push(t_stack **stack, t_stack *new_elem)
{
	if (stack == NULL)
		return ;
	ft_lstadd_front(stack, new_elem);
}

int	pop(t_stack **stack)
{
	t_stack	*temp;
	int		num;

	temp = *stack;
	*stack = temp->next;
	num = temp->num;
	ft_lstdelone(temp);
	return (num);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
