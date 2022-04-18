/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:52:05 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:42:19 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_best_to_top(t_stack **a, t_stack **b, t_stack *elem)
{
	t_stack	*a_next;

	a_next = next_element_to_sort(a, elem);
	while (a_next != *a && elem != *b)
	{
		if (can_share_move(a, b, elem, a_next))
			continue ;
		break ;
	}
	while (a_next != *a)
	{
		if (cost_below_elem(a_next) < cost_above_elem(*a, a_next))
			rra(a, 0);
		else
			ra(a, 0);
	}
	while (elem != *b)
	{
		if (cost_below_elem(elem) < cost_above_elem(*b, elem))
			rrb(b, 0);
		else
			rb(b, 0);
	}
}

static t_stack	*find_cheapest_element(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	t_stack	*temp;
	int		cost;
	int		best_cost;

	temp = *b;
	best_cost = -1;
	while (temp)
	{
		cost = find_element_cost(a, b, temp);
		if (cost < best_cost || best_cost == -1)
		{
			smallest = temp;
			best_cost = cost;
		}
		temp = temp->next;
	}
	return (smallest);
}

static	void	insert_and_sort_b(t_stack **a, t_stack **b, int stack_mean)
{
	t_stack	*min_b;

	min_b = find_min(*b);
	pb(a, b, 0);
	if (ft_lstsize(*b) > 1)
	{
		if ((*b)->num < stack_mean || (*b)->num < min_b->num)
			rb(b, 0);
	}
}

static void	sort_using_mean(t_stack **a, t_stack **b, int stack_mean)
{
	int	current_mean;

	current_mean = find_mean(*a);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->num < current_mean)
			insert_and_sort_b(a, b, stack_mean);
		else
			ra(a, 0);
		sort_using_mean(a, b, stack_mean);
		return ;
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	sort_using_mean(a, b, find_mean(*a));
	sort_three(a);
	while (ft_lstsize(*b))
	{
		get_best_to_top(a, b, find_cheapest_element(a, b));
		pa(a, b, 0);
	}
	get_min_to_top(a, rra);
}
