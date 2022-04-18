/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:05:46 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/08 12:33:42 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

typedef t_list	t_stack;

t_stack	*initialize_stack(int ac, char **av);

t_stack	*new_element(int content);
void	push(t_stack **stack, t_stack *new_elem);
int		pop(t_stack **stack);
int		is_sorted(t_stack *stack);

t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		find_mean(t_stack *stack);
void	get_min_to_top(t_stack **stack, void action(t_stack **, int));

int		check_number(char *item);
int		check_for_repetition(t_stack *stack);
int		check_digit(int argc, char **argv);

void	sa(t_stack **a, int checker_flag);
void	sb(t_stack **b, int checker_flag);
void	ss(t_stack **a, t_stack **b, int checker_flag);

void	pa(t_stack **a, t_stack **b, int checker_flag);
void	pb(t_stack **a, t_stack **b, int checker_flag);

void	ra(t_stack **a, int checker_flag);
void	rb(t_stack **b, int checker_flag);
void	rr(t_stack **a, t_stack **b, int checker_flag);

void	rra(t_stack **a, int checker_flag);
void	rrb(t_stack **b, int checker_flag);
void	rrr(t_stack **a, t_stack **b, int checker_flag);

void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b);

int		cost_above_elem(t_stack *stack, t_stack *elem);
int		cost_below_elem(t_stack *elem);
t_stack	*next_element_to_sort(t_stack **stack, t_stack *current_elem);
int		can_share_move(t_stack **a, t_stack **b,
			t_stack *elem, t_stack *a_next);
int		find_element_cost(t_stack **a, t_stack **b, t_stack *current_elem);

#endif