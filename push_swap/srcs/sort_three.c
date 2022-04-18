/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:21:28 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:42:49 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (find_max(*stack)->next == NULL)
	{
		if ((*stack)->num < (*stack)->next->num)
			return ;
		else
		{
			sa(stack, 0);
			return ;
		}
	}
	else if (find_max(*stack) == *stack)
	{
		ra(stack, 0);
		sort_three(stack);
	}
	else
	{
		rra(stack, 0);
		sort_three(stack);
	}
}
