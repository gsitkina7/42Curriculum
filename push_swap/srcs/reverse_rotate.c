/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:26:08 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:35:47 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	if (*stack && ft_lstsize(*stack) > 1)
	{
		temp = *stack;
		last = ft_lstlast(*stack);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_stack **a, int checker_flag)
{
	if (ft_lstsize(*a) > 1)
	{
		reverse_rotate(a);
		if (!checker_flag)
			ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_stack **b, int checker_flag)
{
	if (ft_lstsize(*b) > 1)
	{
		reverse_rotate(b);
		if (!checker_flag)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack **a, t_stack **b, int checker_flag)
{
	if (ft_lstsize(*a))
		reverse_rotate(a);
	if (ft_lstsize(*b))
		reverse_rotate(b);
	if (!checker_flag)
		ft_putstr_fd("rrr\n", 1);
}
