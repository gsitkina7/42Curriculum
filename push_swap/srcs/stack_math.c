/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:13:04 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:44:12 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*max;

	if (!stack)
		return (NULL);
	temp = stack;
	max = temp;
	while (temp)
	{
		if (temp->num > max->num)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;

	if (!stack)
		return (NULL);
	temp = stack;
	min = temp;
	while (temp)
	{
		if (temp->num < min->num)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	find_mean(t_stack *stack)
{
	t_stack	*temp;
	int		mean;

	temp = stack;
	mean = 0;
	while (temp)
	{
		mean += temp->num;
		temp = temp->next;
	}
	mean = mean / ft_lstsize(stack);
	return (mean);
}

void	get_min_to_top(t_stack **stack, void action(t_stack **, int))
{
	int	min;

	min = find_min(*stack)->num;
	while ((*stack)->num != min)
		action(stack, 0);
}
