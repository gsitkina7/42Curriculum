/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:21:11 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:33:28 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b, int checker_flag)
{
	if (ft_lstsize(*b) > 0)
	{
		push(a, ft_lstnew(pop(b)));
		if (!checker_flag)
			ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack **a, t_stack **b, int checker_flag)
{
	if (ft_lstsize(*a) > 0)
	{
		push(b, ft_lstnew(pop(a)));
		if (!checker_flag)
			ft_putstr_fd("pb\n", 1);
	}
}
