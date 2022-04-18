/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:48 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:40:17 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*elem_1;
	t_stack	*elem_2;
	t_stack	*temp;

	elem_1 = *stack;
	elem_2 = (*stack)->next;
	temp = elem_2->next;
	*stack = elem_2;
	elem_2->next = elem_1;
	elem_1->next = temp;
}

void	sa(t_stack **a, int checker_flag)
{
	if (ft_lstsize(*a) > 1)
	{
		swap(a);
		if (!checker_flag)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack **b, int checker_flag)
{
	if (ft_lstsize(*b) > 1)
	{
		swap(b);
		if (!checker_flag)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack **a, t_stack **b, int checker_flag)
{
	if (ft_lstsize(*a) > 1)
		swap(a);
	if (ft_lstsize(*b) > 1)
		swap(b);
	if (!checker_flag)
		ft_putstr_fd("ss\n", 1);
}
