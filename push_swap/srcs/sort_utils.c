/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:49:19 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:43:42 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cost_above_elem(t_stack *stack, t_stack *elem)
{
	int	diff;

	diff = ft_lstsize(stack) - ft_lstsize(elem);
	return (diff);
}

int	cost_below_elem(t_stack *elem)
{
	return (ft_lstsize(elem));
}

t_stack	*next_element_to_sort(t_stack **stack, t_stack *current_elem)
{
	t_stack	*temp;

	if ((*stack)->num > current_elem->num
		&& ft_lstlast(*stack)->num < current_elem->num)
		return (*stack);
	if (find_min(*stack)->num > current_elem->num)
		return (find_min(*stack));
	else if (find_max(*stack)->num < current_elem->num)
		return (find_max(*stack));
	temp = *stack;
	while (temp->next)
	{
		if (temp->num < current_elem-> num
			&& temp->next->num > current_elem->num)
			break ;
		temp = temp->next;
	}
	if (temp->next)
		return (temp->next);
	else
		return (temp);
}

int	can_share_move(t_stack **a, t_stack **b, t_stack *elem, t_stack *a_next)
{
	if (cost_above_elem(*b, elem) < cost_below_elem(elem))
	{
		if (ft_lstsize(a_next) > ft_lstsize(*a) / 2
			|| cost_above_elem(*a, a_next) < cost_above_elem(*b, elem))
			rr(a, b, 0);
		else
			return (0);
	}
	else
	{
		if (ft_lstsize(a_next) < ft_lstsize(*a) / 2
			|| cost_below_elem(a_next) < cost_below_elem(elem))
			rrr(a, b, 0);
		else
			return (0);
	}
	return (1);
}

int	find_element_cost(t_stack **a, t_stack **b, t_stack *current_elem)
{
	int		cost_for_a;
	int		cost_for_b;
	t_stack	*a_next;

	a_next = next_element_to_sort(a, current_elem);
	if (cost_below_elem(current_elem) < cost_above_elem(*b, current_elem))
		cost_for_b = cost_below_elem(current_elem);
	else
		cost_for_b = cost_above_elem(*b, current_elem);
	if (cost_for_b > cost_below_elem(a_next)
		|| cost_for_b > cost_above_elem(*a, a_next))
		return (cost_for_b);
	if (cost_below_elem(a_next) < cost_above_elem(*a, a_next))
		cost_for_a = cost_below_elem(a_next);
	else
		cost_for_a = cost_above_elem(*a, a_next);
	return (cost_for_a + cost_for_b);
}
