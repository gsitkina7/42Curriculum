/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:30:02 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/05 22:41:11 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	execute_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strncmp("sa\n", command, ft_strlen(command)))
		sa(a, 1);
	else if (!ft_strncmp("sb\n", command, ft_strlen(command)))
		sb(b, 1);
	else if (!ft_strncmp("ss\n", command, ft_strlen(command)))
		ss(a, b, 1);
	else if (!ft_strncmp("pa\n", command, ft_strlen(command)))
		pa(a, b, 1);
	else if (!ft_strncmp("pb\n", command, ft_strlen(command)))
		pb(a, b, 1);
	else if (!ft_strncmp("ra\n", command, ft_strlen(command)))
		ra(a, 1);
	else if (!ft_strncmp("rb\n", command, ft_strlen(command)))
		rb(b, 1);
	else if (!ft_strncmp("rr\n", command, ft_strlen(command)))
		rr(a, b, 1);
	else if (!ft_strncmp("rra\n", command, ft_strlen(command)))
		rra(a, 1);
	else if (!ft_strncmp("rrb\n", command, ft_strlen(command)))
		rrb(b, 1);
	else if (!ft_strncmp("rrr\n", command, ft_strlen(command)))
		rrr(a, b, 1);
	else
		ft_putstr_fd("Error\n", 2);
}

static void	read_in_actions(t_stack **a, t_stack **b)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command || *command == '\n')
			break ;
		execute_command(a, b, command);
	}
	if (is_sorted(*a) && !ft_lstsize(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		a = initialize_stack(argc, argv);
		if (a && !check_for_repetition(a))
			read_in_actions(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
