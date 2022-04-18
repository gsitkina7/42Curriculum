/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:44:34 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 23:32:11 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	if (*stack && ft_lstsize(*stack) > 1)
	{
		first = *stack;
		temp = first;
		while (temp->next)
			temp = temp->next;
		*stack = first->next;
		temp->next = first;
		first->next = NULL;
	}
}

void	ra(t_stack **a, int checker_flag)
{
	if (*a)
	{
		rotate(a);
		if (!checker_flag)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack **b, int checker_flag)
{
	if (*b)
	{
		rotate(b);
		if (!checker_flag)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack **a, t_stack **b, int checker_flag)
{
	if (*a)
		rotate(a);
	if (*b)
		rotate(b);
	if (!checker_flag)
		ft_putstr_fd("rr\n", 1);
}
