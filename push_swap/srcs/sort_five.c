/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:44:59 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/08 12:36:44 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if (ft_lstsize(find_min(*a)) < (ft_lstsize(*a) + 1) / 2)
			get_min_to_top(a, rra);
		else
			get_min_to_top(a, ra);
		if (is_sorted(*a))
			break ;
		if ((*a)->num > (*a)->next->num)
		{
			sa(a, 0);
			continue ;
		}
		pb(a, b, 0);
	}
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	while (ft_lstsize(*b) != 0)
		pa(a, b, 0);
	if (!is_sorted(*a))
		sort_five(a, b);
}
